//
// Created by garre on 11/7/2022.
//

#include "Interpreter.h"

#include <iostream>
#include "Interpreter.h"
#include "Predicate.h"
#include "Header.h"
#include "Tuple.h"
#include "Relation.h"


void Interpreter::get() {
    setSchemes();
    setFacts();
    handleQuery();

}

std::vector<std::string> Interpreter::getParams(Predicate* item) {
    std::vector<std::string> para;
    for(Parameter* paramVec : item->parameter){
        para.push_back(paramVec->parameter);
    }
    return para;
}

void Interpreter::setSchemes() {
    for (Predicate* scheme : d->schemes){
        std::vector<std::string> para = getParams(scheme);
        Header* header = new Header(para);
        Relation* relation = new Relation(scheme->ID, header);
        data->data.insert({relation->name, relation});
    }
}


void Interpreter::setFacts() {
    for (Predicate* fact : d->facts){
        std::vector<std::string> para = getParams(fact);
        Tuple t(para);
        Relation* relation = data->data[fact->ID];
        relation->relation.insert(t);
    }
}

void Interpreter::handleQuery() {
    for(int q =0; q < (int)d->queries.size(); q++){
        if(q!=0){
            std::cout<<'\n';
        }
        d->queries[q]->toString();
        std::cout<<"?";
        std::vector<std::string> para = getParams(d->queries[q]);
        Relation* rel = evaluatePredicate(d->queries[q], para);
        int tu = rel->relation.size();
        if((int)rel->relation.size()>0){


            for(Tuple t : rel->relation){
                tu--;

                for(int i =0; i< (int)t.values.size(); i++){
                    if(i==0){
                        std::cout<<'\n';
                    }
                    if(i == (int)t.values.size()-1){
                        if(i==0){
                            std::cout<<"  "+rel->header->header[i]+'='+t.values[i];

                        }
                        else{
                            std::cout<<" "+rel->header->header[i]+'='+t.values[i];

                        }

                    }
                    else{
                        if(i==0){
                            if((int)t.values.size()==1){
                                std::cout<<" "+rel->header->header[i]+'='+t.values[i];

                            }
                            else{
                                std::cout<<"  "+rel->header->header[i]+'='+t.values[i]+',';

                            }

                        }
                        else{
                            if((int)t.values.size()==1) {
                                std::cout << " " + rel->header->header[i] + '=' + t.values[i];
                            }
                            else{
                                std::cout << " " + rel->header->header[i] + '=' + t.values[i] + ',';

                            }

                        }

                    }

                }


            }
        }


    }
}
Relation* Interpreter::evaluatePredicate(const Predicate* p, std::vector<std::string> para){

    Relation* relation = data->data[p->ID];

    map<std::string, int> forSelect;
    int i = 0;
    std::vector<int> col;
    std::vector<std::string> var;
    for(std::string s : para){
        if(s[0]=='\''){
            relation = relation->selectIndex(i, s);
        }
        else{
            if(forSelect.find(s)!=forSelect.end()){
                relation = relation->selectMatch(forSelect[s], i);
            }
            else{

                forSelect.insert({s, i});
                col.push_back(i);
                var.push_back(s);
            }

        }
        i++;
    }
    if((int)relation->relation.size()>0){
        std::cout<<" Yes(";
        std::cout<<relation->relation.size();
        std::cout<<")";
    }
    else{
        std::cout<<" No";
    }
    relation = relation->project(col);
    relation = relation->rename(var);
    return relation;

}