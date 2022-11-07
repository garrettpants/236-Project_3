cmake_minimum_required(VERSION 3.16)
project(236_Project_3)

set(CMAKE_CXXSTANDARD 17)

include_directories(./Lab1PassOffCases/1-70, Lab1PassOffCases/1-90, Lab1PassOffCases/1-100, Lab2PassOffCases/2-80, Lab2PassOffCases/2-100)

add_executable(236_Project_3
        main.cpp
        Add.h
        Automaton.h
        Colon.h
        ColonDash.h
        Comma.h
        Comment.h
        Facts.h
        ID.h
        Left_Paren.h
        Lexer.cpp
        Lexer.h
        Multiply.h
        Period.h
        Q_Mark.h
        Queries.h
        Right_Paren.h
        Rules.h
        Schemes.h
        String.h
        Token.h
        Datalog.cpp
        Datalog.h Database.h Tuple.h Header.h Relation.h Interpreter.cpp Interpreter.h Relation.cpp Header.cpp)