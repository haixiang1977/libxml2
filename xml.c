/*
 * xml.c
 *
 *  Created on: Jan 18, 2017
 *      Author: liu
 */

// parse the test.xml

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <libxml/parser.h>
#include <libxml/tree.h>

void print_element_names (xmlNode * root_node) {
	xmlNode *cur_node = NULL;

	for (cur_node = root_node; cur_node; cur_node = cur_node->next) {
		if (cur_node->type == XML_ELEMENT_NODE) {
			printf("node type: Element, name: %s\n", cur_node->name);
		}
		if (cur_node->children == NULL) {
			printf("no more children end\n");
		} else {
			print_element_names(cur_node->children);
		}
	}

	return;
}

int main() {
	xmlDocPtr doc; // resulting document tree
	xmlNode *root_element = NULL;

	printf ("xml2 hello world\n");

	/*
	 * this initialize the library and check potential ABI mismatches
	 * between the version it was compiled for and the actual shared
	 * library used.
	 */
	LIBXML_TEST_VERSION

	doc = xmlReadFile("test.xml", NULL, 0);
	if (doc == NULL) {
		printf("Failed to parse test.xml\n");
	}

	/*Get the root element node */
	root_element = xmlDocGetRootElement(doc);

	/* browse the tree */
	print_element_names(root_element);

	xmlFreeDoc(doc);

	xmlCleanupParser();
	return 0;
}
