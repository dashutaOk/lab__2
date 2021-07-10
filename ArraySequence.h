#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H


#include "Sequence.h"
#include "DynamicArray.h"

const string INDEX_OUT_OF_RANGE1 = "Index out of range";

template <typename T> class ArraySequence: public Sequence<T>{
private:
    DynamicArray<T>* dynamicArray;
public:
    //Constructor
    ArraySequence(){
        dynamicArray = new DynamicArray<T>(0);
    }
    ArraySequence(int size){
        dynamicArray = new DynamicArray<T>(size);
    }
    ArraySequence(T* items, int count){
        dynamicArray = new DynamicArray<T>(items, count);
    };
    ArraySequence(ArraySequence<T>* arraySequence){
        this->dynamicArray = arraySequence->dynamicArray;
    }
    ArraySequence(DynamicArray<T>& dynamicArray){
        dynamicArray = new DynamicArray<T>(dynamicArray);
    }
    ArraySequence(DynamicArray<T>* array){
        dynamicArray = array;
    }


    //Destructor
    ~ArraySequence(){
        dynamicArray->Delete_DynamicArray();
    };

    void Delete_ArraySequence(){
        dynamicArray->Delete_DynamicArray();
    }
    //Decomposition
    T GetFirst() override{
        if(this->GetLength() == 0){
            throw out_of_range(INDEX_OUT_OF_RANGE1);
        }
        return dynamicArray->Get(0);
    };//get el on first index
    T GetLast() override{
        if(this->GetLength() == 0){
            throw out_of_range(INDEX_OUT_OF_RANGE1);
        }
        return dynamicArray->Get(dynamicArray->GetSize() - 1);
    };//get el on last index
    T Get(int index) override{
        if(index < 0 || index >= this->GetLength()){
            throw out_of_range(INDEX_OUT_OF_RANGE1);
        }
        return dynamicArray->Get(index);
    };//get index of Node
    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) override{
        if(startIndex < 0 || startIndex >= this->GetLength() || endIndex < 0 || endIndex >= this->GetLength()){
            throw out_of_range(INDEX_OUT_OF_RANGE1);
        }
        ArraySequence<T>* buff = new ArraySequence<T>();
        for(int i = startIndex; i < endIndex; i++)
            buff->Append(this->Get(i));
        return buff;
    };//get list of el
    int GetLength() override{
        return dynamicArray->GetSize();
    };// Length

    //Operations
    void Append(T item) override{
        dynamicArray->Resize(dynamicArray->GetSize() + 1);
        dynamicArray->Set(dynamicArray->GetSize() - 1, item);
    }; //add el at end
    void Prepend(T item) override{
        DynamicArray<T>* new_array = new DynamicArray<T>(dynamicArray->GetSize() + 1);
        new_array->Set(0, item);

        for(int i = 0; i < dynamicArray->GetSize(); i++)
            new_array->Set(i+1, dynamicArray->Get(i));
        dynamicArray = new_array;
    }; //add el at head
    void Set(T item, int index) override{
        if (index < 0 || index >= dynamicArray->GetSize())
            throw out_of_range(INDEX_OUT_OF_RANGE1);
        return dynamicArray->Set(index, item);
    }; //add el at index (replace)
    void InsertAt(T item, int index) override{
        if (index < 0 || index >= dynamicArray->GetSize())
            throw out_of_range(INDEX_OUT_OF_RANGE1);
        dynamicArray->Resize(dynamicArray->GetSize()+1);
        dynamicArray->Resize(dynamicArray->GetSize()+1);
        T this_cell;
        T saved_cell = dynamicArray->Get(index);
        dynamicArray->Set(index, item);
        for(int i = index + 1; i < dynamicArray->GetSize(); i++){
            this_cell = dynamicArray->Get(i);
            dynamicArray->Set(i, saved_cell);
            saved_cell = this_cell;
        }
    }; //add el at index
    ArraySequence <T>* Concat(Sequence <T>* list) override{
        ArraySequence<T>* new_arraySequence = new ArraySequence<T>();
        for (int i = 0; i < dynamicArray->GetSize(); i++)
            new_arraySequence->Append(dynamicArray->Get(i));
        for(int i = 0; i < list->GetLength(); i++)
            new_arraySequence->Append(list->Get(i));
        return new_arraySequence;
    }; //concat two sequence


    //Operators
    T operator[] (int index) override{
        return dynamicArray->Get(index);
    };
};

#endif //ARRAYSEQUENCE_H
