#ifndef PHP_MEMINFO_H
#define PHP_MEMINFO_H 1

#define phpext_meminfo_ptr &meminfo_module_entry

#define MEMINFO_NAME "PHP Meminfo"
#define MEMINFO_VERSION "0.3"
#define MEMINFO_AUTHOR "Benoit Jacquemont"
#define MEMINFO_COPYRIGHT  "Copyright (c) 2010-2017 by Benoit Jacquemont"
#define MEMINFO_COPYRIGHT_SHORT "Copyright (c) 2011-2017"

PHP_FUNCTION(meminfo_objects_list);
PHP_FUNCTION(meminfo_objects_summary);

static int meminfo_instances_count_compare(const void *a, const void *b TSRMLS_DC);

PHP_FUNCTION(meminfo_symbol_table);
PHP_FUNCTION(meminfo_info_dump);


zend_ulong   meminfo_get_element_size(zval* z);

void meminfo_zval_dump(php_stream * stream, char * frame_label, zend_string * symbol_name, zval * zv, HashTable *visited_items, int *first_element);
void meminfo_hash_dump(php_stream *stream, HashTable *ht, zend_bool is_object, HashTable *visited_items, int *first_element);
void meminfo_browse_zvals_from_symbol_table(php_stream *stream, char * frame_label, HashTable *symbol_table, HashTable * visited_items, int *first_element);
void meminfo_browse_zvals_from_op_array(php_stream *stream, char * frame_label, zend_op_array *op_array, zend_execute_data *exec_frame, HashTable * visited_items, int *first_element);
int meminfo_visit_item(char *item_label, HashTable *visited_items);

void meminfo_build_frame_label(char * frame_label, int frame_label_len, zend_execute_data* frame);

char * meminfo_escape_for_json(const char *s);
char * meminfo_info_dump_header(char * header, int header_len);

extern zend_module_entry meminfo_entry;

#endif