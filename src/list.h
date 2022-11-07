#ifndef _LIST_H_
#define _LIST_H_

typedef struct list_entry_s {
  struct list_entry_s* prev;
  struct list_entry_s* next;
} list_entry_t;

static inline void _list_insert(list_entry_t* elm, list_entry_t* prev,
                                list_entry_t* next) {
  prev->next = next->prev = elm;

  elm->next = next;
  elm->prev = prev;
}

static inline void _list_remove(list_entry_t* prev, list_entry_t* next) {
  prev->next = next;
  next->prev = prev;
}

static inline void list_init(list_entry_t* elm) {
  elm->prev = elm->next = elm;
}

static inline void list_insert_before(list_entry_t* list, list_entry_t* elm) {
  _list_insert(elm, list->prev, list);
}

static inline void list_insert_after(list_entry_t* list, list_entry_t* elm) {
  _list_insert(elm, list, list->next);
}

static inline void list_insert(list_entry_t* list, list_entry_t* elm) {
  list_insert_after(list, elm);
}

static inline void list_remove(list_entry_t* elm) {
  _list_remove(elm->prev, elm->next);
}

static inline void list_remove_init(list_entry_t* elm) {
  list_remove(elm);
  list_init(elm);
}

static inline int list_empty(list_entry_t* list) {
  return list->next == list;
}

static inline list_entry_t* list_next(list_entry_t* elm) {
  return elm->next;
}

static inline list_entry_t* list_prev(list_entry_t* elm) {
  return elm->prev;
}

#endif  // _LIST_H_
