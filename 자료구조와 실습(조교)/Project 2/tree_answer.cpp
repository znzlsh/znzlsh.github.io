
#include <stdlib.h>
#include <stdio.h>
#include <string>

typedef struct emp{
	emp *super;
	emp *sub;
	emp *l_sibling;
	emp *r_sibling;
	char name[20];
};
emp *root;

void print(emp *node, int level);
void hire(char *superName);
void fire();
emp* createEmp(char *subName);
emp *findEmp(emp *node, char *empName);
void insert(emp *super, emp *sub);
void deleteEmp(emp *fireEmp);
emp *promoteSub(emp *node);
void setSuper(emp *super, emp *node);

void main(){
	root = (emp*)malloc(sizeof(emp));
	root->super = NULL;	root->sub = NULL;
	root->l_sibling = NULL; root->r_sibling = NULL;
	scanf("%s", root->name);

	char command[50];
	while (1){
		scanf("%s", command);
		if (strcmp(command, "Print") == 0) {
			print(root, 0);
			printf("------------------------\n");
		}
		else if (strcmp(command, "Fire") == 0) fire();
		else if (strcmp(command, "Quit") == 0) break;
		else hire(command);
	}
}
emp* createEmp(char *subName){
	emp *temp;
	temp = (emp*)malloc(sizeof(emp));
	temp->super = NULL;	temp->sub = NULL;
	temp->l_sibling = NULL; temp->r_sibling = NULL;
	strcpy(temp->name, subName);
	return temp;
}
void print(emp *node, int level){
	emp *temp = node;
	if (temp == NULL) return;

	for (int i = 0; i < level; i++) printf("+");
	printf("%s\n", temp->name);
	if (temp->sub != NULL) print(temp->sub, (level + 1));
	if (temp->r_sibling != NULL) print(temp->r_sibling, level);
}
emp *findEmp(emp *node, char *empName){
	emp *tempSuper = node;
	emp *tempSub;
	emp *result = NULL;
	if (node == NULL) return NULL;
	if (strcmp(node->name, empName) == 0) return node;  //��Ʈ�϶�

	if(tempSuper != NULL){
		tempSub = tempSuper->sub;
		while (tempSub != NULL){  //�ڽ� ��尡 �ִ°��
			if (strcmp(tempSub->name, empName) == 0) return tempSub;  //ù��° �ڽ��� ã�� ����϶�
			else result = findEmp(tempSub, empName);//�ڽĳ�忡 �ڽ� ��尡 ������
			if (result != NULL) return result;
			tempSub = tempSub->r_sibling; //���� ���� �̵�
		}
	}
	return result;
}
void hire(char *superName){
	char command[20];
	scanf("%s", command);
	if (strcmp(command, "hire") != 0){
		scanf("%s", command);
		printf("Command Error\n");
		return;
	}

	char subName[20];
	scanf("%s", subName);
	emp *sub = createEmp(subName);

	emp *super = findEmp(root, superName);
	insert(super, sub);
}
void insert(emp *super, emp *sub){
	emp *temp = super->sub;
	//ù��° �ڽ��϶�
	if (temp == NULL){
		super->sub = sub;
		sub->super = super;
		return;
	}
	//�ι�° �̻� �ڽ��϶�
	while (temp->r_sibling != NULL){
		temp = temp->r_sibling;
	}
	temp->r_sibling = sub;
	sub->l_sibling = temp;
	sub->super = temp->super;
}
void fire(){
	char fireEmpName[20];
	scanf("%s", fireEmpName);
	emp *fireEmp = findEmp(root, fireEmpName);
	if (fireEmp == NULL){
		printf("No such Employee\n");
		return;
	}
	deleteEmp(fireEmp);
}
void deleteEmp(emp *fireEmp){
	//1. �ڽ��� ���� ��� �׳� ����
	if (fireEmp->sub == NULL){
		if (fireEmp->l_sibling == NULL){  //ù��° �ڽ��ΰ��
			if (fireEmp->r_sibling != NULL){  //���� ������
				fireEmp->super->sub = fireEmp->r_sibling;
				fireEmp->r_sibling->l_sibling = NULL;
				free(fireEmp);
			}
			else{     //���� ������
				fireEmp->super->sub = NULL;
				free(fireEmp);
			}
		}
		else{    //�ι�° �̻� �ڽ��ΰ��
			if (fireEmp->r_sibling != NULL){  //���� ������
				fireEmp->l_sibling->r_sibling = fireEmp->r_sibling;
				fireEmp->r_sibling->l_sibling = fireEmp->l_sibling;
				free(fireEmp);
			}
			else{  //���� ������
				fireEmp->l_sibling->r_sibling = NULL;
				free(fireEmp);
			}
		}
	}

	//2. �ڽ� �ִ°��
	else{
		emp *replace = promoteSub(fireEmp->sub);
		if (fireEmp->l_sibling == NULL){  //ù��° �ڽ��ΰ��
			fireEmp->super->sub = replace;
			replace->super = fireEmp->super;
			setSuper(replace->super, replace->r_sibling);
			free(fireEmp);
		}
		else{    //�ι�° �̻� �ڽ��ΰ��
			fireEmp->l_sibling->r_sibling = replace;
			replace->l_sibling = fireEmp->l_sibling;
			free(fireEmp);
		}
	}

}
//������ �� �ڽ��� ������Ų��.
emp *promoteSub(emp *node){
	if (node->sub == NULL){
		node->sub = node->r_sibling;
		if (node->r_sibling!=NULL)
			node->r_sibling->l_sibling = NULL;
		setSuper(node, node->r_sibling);

		node->r_sibling = node->super->r_sibling;
		if (node->r_sibling !=NULL)
			node->r_sibling->l_sibling = node;
		return node;
	}
	else{
		emp *temp = promoteSub(node->sub);
		node->sub = temp;
		temp->super = node;
		setSuper(node, temp->r_sibling);

		node->r_sibling = node->super->r_sibling;
		node->super->r_sibling->l_sibling = node;
		setSuper(node->super, node->r_sibling);
		return node;
	}
}
void setSuper(emp *super, emp *node){
	if (node == NULL) return;
	while (node->r_sibling != NULL){
		node->super = super;
		node = node->r_sibling;
	}
}