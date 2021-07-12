#pragma once
#ifndef LAB_2_MENU_VECTOR_H
#define LAB_2_MENU_VECTOR_H

#include <string>
#include <iostream>
#include <cstdio>
#include "vector.h"
#include "menu_LinearForm.h"

int chooseVectorFunction(){
    int func;
    std::cout << "What function do you want to use?: \n"
         << "\t1: Sum of Vectors\n"
         << "\t2: Multiplication of scalar and vector\n"
         << "\t3: Vector Norm\n"
         << "\t4: Scalar Multiplication\n"
         << "\t5: Vector tests\n" << std::endl
         << "\t0: Return to select type\n"
         << "Enter a number: ";
    std::cin >> func;
    return func;
}

template <typename T>
Vector<T>* inputVector(){
    int dim;
    std::cout << "Enter a dimension of vector:";
    std::cin >> dim; cout << endl;
    Vector<T>* vect = new Vector<T>();
    std::cout << "Enter Coordinates (one by one):" << std::endl;
    T coord;
    for(int i = 0; i < dim; i++){
        std::cin >> coord;
        vect->Append(coord);
    }
    return vect;
}
Vector<complex<double>>* inputComplexVector() {
    int dim;
    std::cout << "Enter a dimension of vector:";
    std::cin >> dim; std::cout << std::endl;
    Vector<complex<double>>* vect = new Vector<complex<double>>();
    std::cout << "Enter Coordinates (one by one):" << std::endl;
    complex<double> coord;
    double real, im;
    for(int i = 0; i < dim; i++){
        std::cout << "Enter Real and Imaginary number (separated by a space): " << std::endl;
        std::cin >> real >> im;
        coord = complex<double>(real, im);
        vect->Append(coord);
    }
    return vect;
}

void MenuVector(){
    while(true) {
        int type = chooseType(); //1 - int ; 2 - double ; 3 - complex; 0 - return to select class
        if (type == 0){
            break;
        }
        if (type == 1) {
            while (true) {
                int function = chooseVectorFunction();
                if (function == 1) {
                    std::cout << "Enter 1 vector:" << std::endl;
                    auto* vect1 = inputVector<int>();
                    std::cout << "Enter 2 vector:" << std::endl;
                    auto* vect2 = inputVector<int>();
                    std::cout << "Vector 1 = " << vect1 << std::endl;
                    std::cout << "Vector 2 = " << vect2 << std::endl;
                    auto* sum = vect1->SumOfVectors(vect2);
                    std::cout << "Sum of Vector 1 and Vector 2 = " << sum << std::endl;
                }
                else if (function == 2) {
                    std::cout << "Enter vector:" << std::endl;
                    auto* vect = inputVector<int>();
                    std::cout << "Enter scalar: " << std::endl;
                    int scalar;
                    std::cin >> scalar;
                    std::cout << "Vector = " << vect << std::endl;
                    std::cout << "Scalar = " << scalar << std::endl;
                    auto vectorMult = vect->MultOnScalar(scalar);
                    std::cout << "Multiplication of vector and scalar = " << vectorMult << std::endl;
                }
                else if (function == 3) {
                    std::cout << "Enter vector:" << std::endl;
                    auto* vect = inputVector<int>();
                    std::cout << "Vector = " << vect << std::endl;
                    auto vectorNorm = vect->NormOfVector<double>();
                    std::cout << "Vector norm = " << vectorNorm << std::endl;
                }
                else if (function == 4) {
                    std::cout << "Enter 1 vector:" << std::endl;
                    auto* vect1 = inputVector<int>();
                    std::cout << "Enter 2 vector:" << std::endl;
                    auto* vect2 = inputVector<int>();
                    std::cout << "Vector 1 = " << vect1 << std::endl;
                    std::cout << "Vector 2 = " << vect2 << std::endl;
                    auto mult = vect1->ScalarMult(vect2);
                    std::cout << "Scalar multiplication of Vector 1 and Vector 2 = " << mult << std::endl;
                }
                else if (function == 0) break;
                else
                    std::cout << "Enter the correct number!" << std::endl;
                std::cout << sep << std::endl;
            }
        }
        else if (type == 2) {
            while(true) {
                int function = chooseVectorFunction();
                if (function == 1) {
                    std::cout << "Enter 1 vector:" << std::endl;
                    auto *vect1 = inputVector<double>();
                    std::cout << "Enter 2 vector:" << std::endl;
                    auto *vect2 = inputVector<double>();
                    std::cout << "Vector 1 = " << vect1 << std::endl;
                    std::cout << "Vector 2 = " << vect2 << std::endl;
                    auto *sum = vect1->SumOfVectors(vect2);
                    std::cout << "Sum of Vector 1 and Vector 2 = " << sum << std::endl;
                }
                else if (function == 2) {
                    std::cout << "Enter vector:" << std::endl;
                    auto *vect = inputVector<double>();
                    std::cout << "Enter scalar: " << std::endl;
                    double scalar;
                    std::cin >> scalar;
                    std::cout << "Vector = " << vect << std::endl;
                    std::cout << "Scalar = " << scalar << std::endl;
                    auto vectorMult = vect->MultOnScalar(scalar);
                    std::cout << "Multiplication of vector and scalar = " << vectorMult << std::endl;
                }
                else if (function == 3) {
                    std::cout << "Enter vector:" << std::endl;
                    auto *vect = inputVector<double>();
                    std::cout << "Vector = " << vect << std::endl;
                    auto vectorNorm = vect->NormOfVector<double>();
                    std::cout << "Vector norm = " << vectorNorm << std::endl;
                }
                else if (function == 4) {
                    std::cout << "Enter 1 vector:" << std::endl;
                    auto *vect1 = inputVector<double>();
                    std::cout << "Enter 2 vector:" << std::endl;
                    auto *vect2 = inputVector<double>();
                    std::cout << "Vector 1 = " << vect1 << std::endl;
                    std::cout << "Vector 2 = " << vect2 << std::endl;
                    auto mult = vect1->ScalarMult(vect2);
                    std::cout << "Scalar multiplication of Vector 1 and Vector 2 = " << mult << std::endl;
                }
                else if (function == 0) break;
                else
                    std::cout << "Enter the correct number!" << std::endl;
                std::cout << sep << std::endl;
            }
        }
        else if (type == 3) {
            while(true) {
                int function = chooseVectorFunction();
                if (function == 1) {
                    std::cout << "Enter 1 vector:" << std::endl;
                    auto *vect1 = inputComplexVector();
                    std::cout << "Enter 2 vector:" << std::endl;
                    auto *vect2 = inputComplexVector();
                    std::cout << "Vector 1 = " << vect1 << std::endl;
                    std::cout << "Vector 2 = " << vect2 << std::endl;
                    auto *sum = vect1->SumOfVectors(vect2);
                    std::cout << "Sum of Vector 1 and Vector 2 = " << sum << std::endl;
                }
                else if (function == 2) {
                    std::cout << "Enter vector:" << std::endl;
                    auto *vect = inputComplexVector();
                    std::cout << "Enter scalar: " << std::endl;
                    complex<double> scalar;
                    double real, im;
                    std::cout << "Enter Real and Imaginary number (separated by a space): " << std::endl;
                    std::cin >> real >> im;
                    scalar = complex<double>(real, im);
                    std::cout << "Vector = " << vect << std::endl;
                    std::cout << "Scalar = " << scalar << std::endl;
                    auto vectorMult = vect->MultOnScalar(scalar);
                    std::cout << "Multiplication of vector and scalar = " << vectorMult << std::endl;
                }
                else if (function == 3) {
                    std::cout << "Enter vector:" << std::endl;
                    auto *vect = inputComplexVector();
                    std::cout << "Vector = " << vect << std::endl;
                    auto vectorNorm = vect->NormOfVector<complex<double>>();
                    std::cout << "Vector norm = " << vectorNorm << std::endl;
                }
                else if (function == 4) {
                    std::cout << "Enter 1 vector:" << std::endl;
                    auto *vect1 = inputComplexVector();
                    std::cout << "Enter 2 vector:" << std::endl;
                    auto *vect2 = inputComplexVector();
                    std::cout << "Vector 1 = " << vect1 << std::endl;
                    std::cout << "Vector 2 = " << vect2 << std::endl;
                    auto mult = vect1->ScalarMult(vect2);
                    std::cout << "Scalar multiplication of Vector 1 and Vector 2 = " << mult << std::endl;
                }
                else if (function == 0) break;
                else
                    std::cout << "Enter the correct number!" << std::endl;
                std::cout << sep << std::endl;
            }
        }
    }
}


#endif //LAB_2_MENU_VECTOR_H
