#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define PLAYER_X '+'
#define PLAYER_O '-'

struct game_node {
	int val;
	int turn;
	char pos[3][3];
	struct game_node *cptr;
	struct game_node *sptr;
};

struct game_node *get_node(void)
{
	struct game_node *new_node;

	if( (new_node = malloc(sizeof(struct game_node))) == NULL) {
		fprintf(stderr, "Error game node could not be created\n");
		exit(EXIT_FAILURE);
	}

	return new_node;
}

struct game_node *make_tree(char *baord[], int lev)
{
	struct game_node *root;

	/* Set up root node of tree */
	root = get_node();
	root->cptr = NULL;
	root->sptr = NULL;
	root->turn = PLAYER_X;
	strncpy(root->pos, baord, sizeof(root->pos) - 1);

	/* build rest of game tree */
	game_tree(root, lev, 0);

	return root;
	
}

void game_tree(struct gnode *root, int max_level, int cur_level)
{
	struct gnode *tmp;

	if(cur_level == max_level)
		return;
	
	//gen_pos(root);

	for(tmp = root->cptr; tmp != NULL; tmp = tmp->sptr) {
		tmp->turn = -root->turn;
		game_tree(tmp, max_level; cur_level + 1);
	}
}