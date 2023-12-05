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