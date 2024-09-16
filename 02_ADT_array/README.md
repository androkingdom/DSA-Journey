# Psudeocode
**Data Structure**: List
```c
typedef struct List{
    int* ptr;
    int* size;
} List;
```
## Functions
- **`InitList(List* ListVar, int size)`**
- **`SetElement(List* ListVar, int array[])`**
- **`GetElementAt(List* ListVar, int index)`**
- **`ShowList(List* ListVar)`**
- **`IndexOf(List* ListVar, int number)`**
- **`Max(List* ListVar)`**
- **`Min(List* ListVar)`**
- **`SumAll(List* ListVar)`**
- **`Contain(List* ListVar, int number)`**
- **`FreeAll(List* ListVar)`**