//
// Created by garre on 11/7/2022.
//

#include "Interpreter.h"
#include <iostream>
#include "Predicate.h"
#include "Header.h"
#include "Tuple.h"
#include "Relation.h"

using namespace std;


void Interpreter::get() {
    setSchemes();
    setFacts();
    handleQuery();

}

vector<string> Interpreter::getParams(Predicate* item) {
    vector<string> para;
    for(Parameter* paramVec : item->parameter){
        para.push_back(paramVec->parameter);
    }
    return para;
}

void Interpreter::setSchemes() {
    for (Predicate* scheme : d->schemes){
        vector<string> para = getParams(scheme);
        Header* header = new Header(para);
        Relation* relation = new Relation(scheme->ID, header);
        data->data.insert({relation->name, relation});
    }
}


void Interpreter::setFacts() {
    for (Predicate* fact : d->facts){
        vector<string> para = getParams(fact);
        Tuple t(para);
        Relation* relation = data->data[fact->ID];
        relation->relation.insert(t);
    }
}

void Interpreter::handleQuery() {
    for(int q =0; q < (int)d->queries.size(); q++){
        if(q!=0){
            cout<<'\n';
        }
        d->queries[q]->toString();
        cout<<"?";
        vector<string> para = getParams(d->queries[q]);
        Relation* rel = evaluatePredicate(d->queries[q], para);
        int tu = rel->relation.size();
        if((int)rel->relation.size()>0){


            for(Tuple t : rel->relation){
                tu--;

                for(int i =0; i< (int)t.values.size(); i++){
                    if(i==0){
                        cout<<'\n';
                    }
                    if(i == (int)t.values.size()-1){
                        if(i==0){
                            cout<<"  "+rel->header->header[i]+'='+t.values[i];

                        }
                        else{
                            cout<<" "+rel->header->header[i]+'='+t.values[i];

                        }

                    }
                    else{
                        if(i==0){
                            if((int)t.values.size()==1){
                                cout<<" "+rel->header->header[i]+'='+t.values[i];

                            }
                            else{
                                cout<<"  "+rel->header->header[i]+'='+t.values[i]+',';

                            }

                        }
                        else{
                            if((int)t.values.size()==1) {
                                cout << " " + rel->header->header[i] + '=' + t.values[i];
                            }
                            else{
                                cout << " " + rel->header->header[i] + '=' + t.values[i] + ',';

                            }

                        }

                    }

                }


            }
        }


    }
}
Relation* Interpreter::evaluatePredicate(const Predicate* p, vector<string> para){

    Relation* relation = data->data[p->ID];

    map<string, int> forSelect;
    int i = 0;
    vector<int> col;
    vector<string> var;
    for(string s : para){
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
        cout<<" Yes(";
        cout<<relation->relation.size();
        cout<<")";
    }
    else{
        cout<<" No";
    }
    relation = relation->project(col);
    relation = relation->rename(var);
    return relation;

}