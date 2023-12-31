typedef struct _dlnode_
{
    struct _dlnode_ *next, *prev;
    void *data;
} DLNode;

typedef struct _dllist_
{
    DLNode *first;
    DLNode *cur;

} DLList;

typedef struct _slnode_
{
    struct _slnode_ *next;
    void *data;
} SLNode;

typedef struct _sllist_
{
    SLNode *first;
    SLNode *cur;

} SLList;

typedef struct _cslnode_
{
    struct _cslnode_ *next;
    void *data;
} CSLNode;

typedef struct _csllist_
{
    CSLNode *first;
    CSLNode *cur;

} CSLList;

typedef struct _cdlnode_
{
    struct _cdlnode_ *next, *prev;
    void *data;
} CDLNode;

typedef struct _cdllist_
{
    CDLNode *first;
    CDLNode *cur;

} CDLList;

DLList *dllcreate();
SLList *sllcreate();
CSLList *csllcreate();
CDLList *cdllcreate();

int sllInsertAsFirst(SLList *l, void *data);
int dllInsertAsFirst(DLList *l, void *data);
int csllInsertAsFirst(CSLList *l, void *data);
int cdllInsertAsFirst(CDLList *l, void *data);

int sllInsertAsLast(SLList *l, void *data);
int dllInsertAsLast(DLList *l, void *data);
int csllInsertAsLast(CSLList *l, void *data);
int cdllInsertAsLast(CDLList *l, void *data);

int sllInsertKPosition(SLList *l, void *data, int k);
int dllInsertKPosition(DLList *l, void *data, int k);
int csllInsertKPosition(CSLList *l, void *data, int k);
int cdllInsertKPosition(CDLList *l, void *data, int k);

int sllInsertAfterKey(SLList *l, void *key, void *data, int (*cmp)(void *, void *));
int dllInsertAfterKey(DLList *l, void *key, void *data, int (*cmp)(void *, void *));
int csllInsertAfterKey(CSLList *l, void *key, void *data, int (*cmp)(void *, void *));
int cdllInsertAfterKey(CDLList *l, void *key, void *data, int (*cmp)(void *, void *));

int sllInsertBeforeKey(SLList *l, void *key, void *data, int (*cmp)(void *, void *));
int dllInsertBeforeKey(DLList *l, void *key, void *data, int (*cmp)(void *, void *));
int csllInsertBeforeKey(CSLList *l, void *key, void *data, int (*cmp)(void *, void *));
int cdllInsertBeforeKey(CDLList *l, void *key, void *data, int (*cmp)(void *, void *));

int sllInsertOrdenedList(SLList *l, void *key, int (*cmp)(void *, void *));
int dllInsertOrdenedList(DLList *l, void *key, int (*cmp)(void *, void *));
int csllInsertOrdenedList(CSLList *l, void *key, int (*cmp)(void *, void *));
int cdllInsertOrdenedList(CDLList *l, void *key, int (*cmp)(void *, void *));

void *sllRemoveFirst(SLList *l);
void *dllRemoveFirst(DLList *l);
void *csllRemoveFirst(CSLList *l);
void *cdllRemoveFirst(CDLList *l);

void *sllRemoveLast(SLList *l);
void *dllRemoveLast(DLList *l);
void *csllRemoveLast(CSLList *l);
void *cdllRemoveLast(CDLList *l);

void *sllRemoveKPosition(SLList *l, int k);
void *dllRemoveKPosition(DLList *l, int k);
void *csllRemoveKPosition(CSLList *l, int k);
void *cdllRemoveKPosition(CDLList *l, int k);

void *sllRemoveByKey(SLList *l, void *key, int (*cmp)(void *, void *));
void *dllRemoveByKey(DLList *l, void *key, int (*cmp)(void *, void *));
void *csllRemoveByKey(CSLList *l, void *key, int (*cmp)(void *, void *));
void *cdllRemoveByKey(CDLList *l, void *key, int (*cmp)(void *, void *));

void *sllRemoveAfterKey(SLList *l, void *key, int (*cmp)(void *, void *));
void *dllRemoveAfterKey(DLList *l, void *key, int (*cmp)(void *, void *));
void *csllRemoveAfterKey(CSLList *l, void *key, int (*cmp)(void *, void *));
void *cdllRemoveAfterKey(CDLList *l, void *key, int (*cmp)(void *, void *));

void *sllRemoveBeforeKey(SLList *l, void *key, int (*cmp)(void *, void *));
void *dllRemoveBeforeKey(DLList *l, void *key, int (*cmp)(void *, void *));
void *csllRemoveBeforeKey(CSLList *l, void *key, int (*cmp)(void *, void *));
void *cdllRemoveBeforeKey(CDLList *l, void *key, int (*cmp)(void *, void *));

void *sllConcatenateLists(SLList *l, SLList *k);
void *dllConcatenateLists(DLList *l, DLList *k);
void *csllConcatenateLists(CSLList *l, CSLList *k);
void *cdllConcatenateLists(CDLList *l, CDLList *k);

int sllFreeNodes(SLList *l);
int dllFreeNodes(DLList *l);
int csllFreeNodes(CSLList *l);
int cdllFreeNodes(CDLList *l);

void *sllInvertList(SLList *l);
void *dllInvertList(DLList *l);
void *csllInvertList(CSLList *l);
void *cdllInvertList(CDLList *l);

void *sllCombineOrdenedLists(SLList *l, SLList *k, int (*cmp)(void *, void *));
void *dllCombineOrdenedLists(DLList *l, DLList *k, int (*cmp)(void *, void *));
void *csllCombinedOrdenedLists(CSLList *l, CSLList *k, int (*cmp)(void *, void *));
void *cdllCombineOrdenedLists(CDLList *l, CDLList *k, int (*cpm)(void *, void *));

void *sllJoinLists(SLList *l, SLList *k);
void *dllJoinLists(DLList *l, DLList *k);
void *csllJoinLists(CSLList *l, CSLList *k);
void *cdllJoinLists(CDLList *l, CDLList *k);

void *sllIntersectionLists(SLList *l, SLList *k, int (*cmp)(void *, void *));
void *dllIntersectionLists(DLList *l, DLList *k, int (*cmp)(void *, void *));
void *csllIntersectionLists(CSLList *l, CSLList *k, int (*cmp)(void *, void *));
void *cdllIntersectionLists(CDLList *l, CDLList *k, int (*cmp)(void *, void *));

int sllSumList(SLList *l);
int dllSumList(DLList *l);
int csllSumList(CSLList *l);
int cdllSumList(CDLList *l);

int sllNumberElements(SLList *l);
int dllNumberElements(DLList *l);
int csllNumberElements(CSLList *l);
int cdllNumberElements(CDLList *l);

void *sllCreateCopyList(SLList *l);
void *dllCreateCopyList(DLList *l);
void *csllCreateCopyList(CSLList *l);
void *cdllCreateCopyList(CDLList *l);

int sllVerifyEqualsLists(SLList *l, SLList *k, int (*cmp)(void *, void *));
int dllVerifyEqualsLists(DLList *l, DLList *k, int (*cmp)(void *, void *));
int csllVerifyEqualsLists(CSLList *l, CSLList *k, int (*cmp)(void *, void *));
int cdllVerifyEqualsLists(CDLList *l, CDLList *k, int (*cmp)(void *, void *));


void *sllSplitList(SLList *l, int k);
void *dllSplitList(DLList *l, int k);
void *csllSplitList(CSLList *l, int k);
void *cdllSplitList(CDLList *l, int k);


void *sllremoveNElements(SLList *l, int n);
void *dllRemoveNElements(DLList *l, int n);
void *csllRemoveNElements(CSLList *l, int n);
void *cdllRemoveNElements(CDLList *l, int n);


int sllDetectCycle(SLList *l);
int dllDetectCycle(DLList *l);
int csllDetectCycle(CSLList *l);
int cdllDetectCycle(CDLList *l);

void *sllRemoveDuplicateData(SLList *l, int(*cmp)(void *, void*));
void *dllRemoveDuplicateData(DLList *l, int(*cmp)(void *, void*));
void *csllRemoveDuplicateData(CSLList *l, int(*cmp)(void *, void*));
void *cdllRemoveDuplicateData(CDLList *l, int(*cmp)(void *, void*));


void *sllRemoveConsecutiveDuplicateData(SLList *l, int(*cmp)(void *, void *));
void *dllRemoveConsecutiveDuplicateData(DLList *l, int(*cmp)(void *, void *));
void *csllRemoveConsecutiveDuplicateData(CSLList *l, int(*cmp)(void *, void *));
void *cdllRemoveConsecutiveDuplicateData(CDLList *l, int(*cmp)(void *, void *));


void *sllReturnKFromLast(SLList *l, int k);
void *dllReturnKFromLast(DLList *l, int k);
void *csllReturnKFromLast(CSLList *l, int k);
void *cdllReturnKFromLast(CDLList *l, int k);


int sllIsPalindrome(SLList *l, int(*cmp)(void *, void *));
int dllIsPalindrome(DLList *l, int(*cmp)(void *, void *));
int csllIsPalindrome(CSLList *l, int(*cmp)(void *, void*));
int cdllIsPalindrome(CDLList *l, int(*cmp)(void*, void*));


int sllSplitListAllocatingNodes(SLList *l, SLList *firstList, SLList *secondList);
int dllSplitListAllocatingNodes(DLList *l, DLList *firstList, SLList *secondList);
int csllSplitListAllocatingNodes(CSLList *l, CSLList *firstList, CSLList *secondList);
int cdllSplitListAllocatingNodes(CDLList *l, CDLList *firstList, CDLList *secondList);


int sllSplitListNotAllocatingNodes(SLList *l, SLList *firstList, SLList *secondList);
int dllSplitListNotAllocatingNodes(DLList *l, DLList *firstList, DLList *secondList);
int csllSplitListNotAllocatingNodes(CSLList *l, CSLList *firstList, CSLList *secondList);
int cdllSplitListNotAllocatingNodes(CDLList *l, CDLList *firstList, CDLList *secondList);


void *sllGetMiddleElement(SLList *l);
void *dllGetMiddleElement(DLList *l);
void *csllGetMiddleElement(CSLList *l);
void *cdllGetMiddleElement(CDLList *l);


int sllInsertInMiddle(SLList *l, void *data);
int dllInsertInMiddle(DLList *l, void *data);
int csllInsertInMiddle(CSLList *l, void *data);
int cdllInsertInMiddle(CDLList *l, void *data);


int sllListLength(SLList *l);
int dllListLength(DLList *l);
int csllListLength(CSLList *l);
int cdllListLength(CDLList *l);


int sllIsEquals(SLList *l, SLList *k, int(*cmp)(void*, void*));
int dllIsEquals(DLList *l, DLList *k, int(*cmp)(void*, void*));
int csllIsEquals(CSLList *l, CSLList *k, int(*cmp)(void*, void*));
int cdllIsEquals(CDLList *l, CDLList *k, int(*cmp)(void*, void*));


void *sllReturnL2Copy(SLList *l1, SLList *l2);
void *dllReturnL2Copy(DLList *l1, DLList *l2);
void *csllReturnL2Copy(CSLList *l1, CSLList *l2);
void *cdllReturnL2Copy(CDLList *l1, CDLList *l2);


void *sllReturnDifference(SLList *l, SLList *l1, SLList *l2, int(*cmp)(void *, void *));
void *dllReturnDifference(DLList *l, DLList *l1, DLList *l2, int(*cmp)(void *, void *));
void *csllReturnDifference(CSLList *l, CSLList *l1, CSLList *l2, int(*cmp)(void *, void *));
void *cdllReturnDifference(CDLList *l, CDLList *l1, CDLList *l2, int(*cmp)(void *, void *));


int sllNumberEqualValue(SLList *l, SLList *k, int(*cmp)(void *, void *));
int dllNumberEqualValue(DLList *l, DLList *k, int(*cmp)(void *, void *));
int csllNumberEqualValue(CSLList *l, CSLList *k, int(*cmp)(void *, void *));
int cdllNumberEqualValue(CDLList *l, CDLList *k, int(*cmp)(void *, void *));


int sllRemoveEvenNodes(SLList *l);
int dllRemoveEvenNodes(DLList *l);
int csllRemoveEvenNodes(CSLList *l);
int cdllRemoveEvenNodes(CDLList *l);


int sllRemoveOddNodes(SLList *l);
int dllRemoveOddNodes(DLList *l);
int csllRemoveOddNodes(CSLList *l);
int cdllRemoveOddNodes(CDLList *l);

int sllSplitListInOddsAndEvens(SLList *l, SLList *l1, SLList *l2);
int dllSplitListInOddsAndEvens(DLList *l, DLList *l1, DLList *l2);
int csllSplitListInOddsAndEvens(CSLList *l, CSLList *l1, CSLList *l2);
int cdllSplitListInOddsAndEvens(CDLList *l, CDLList *l1, CDLList *l2);

int sllSwitchKeys(SLList *l, void *key1, void *key2, int(*cmp)(void *, void *));
int dllSwitchKeys(DLList *l, void *key1, void *key2, int(*cmp)(void *, void *));
int csllSwitchKeys(CSLList *l, void *key1, void *key2, int(*cmp)(void *, void *));
int cdllSwitchKeys(CDLList *l, void *key1, void *key2, int(*cmp)(void *, void *));


//questao 1 prova 2022.1
int ÉInversa(CDLList *l1, CDLList *l2);


//questão 2 prova 2022.1
void PegaElementosIguais(DLList *l1, DLList *l2, DLList *l3);

//questão 1 prova 2017.1
SLList *sllCumulativeSum(SLList *l1, int(*getValue)(void *));


int removeOCaraEOsVizinhos(CDLList *l, void *key, int(*cmp)(void *, void*));

void *sllInverter(SLList *l);

void *dllInverter(DLList *l);

void *intercalarDuasListas(CSLList *l1, CSLList *l2);