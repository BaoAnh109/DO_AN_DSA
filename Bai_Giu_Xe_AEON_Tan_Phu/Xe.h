#pragma once
#include "AddInclude.h"
#include "SNode.h"

void swap(ItemType& a, ItemType& b);
int compareDate(DATE date1, DATE date2);
int compare(ItemType& a, ItemType& b);
void qickSort(ItemType arr[], int left, int right);
void sortStackByDonGia(Stack& st);
void nhapNgay(DATE& date);
void nhapTTXe(ItemType& x);
void createStack_InputByHand(Stack& st);
void loadTTXe(FILE* fi, ItemType& x);
void createStack_FromTextFile(Stack& st, char inputFileName[]);
void saveTTXe(FILE* fo, ItemType x);
void saveStack_ToTextFile(Stack st, char inputFileName[]);
std::unordered_map<std::string, int> countByLoaiXe(Stack st);
void showLoaiXeMax(Stack st);
void process_QLXe(Stack &st, char tenFile_dsxe[]);
void process_QLDoanhThu(Stack st);
