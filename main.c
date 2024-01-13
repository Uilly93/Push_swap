/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:15:32 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/13 10:55:53 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack **stack, char *name){
	ft_printf("this is %s stack\n", name);
	t_stack *current = *stack;
	while(current){
		ft_printf("%d -> ", current->content);
		current = current->next;
	}
	ft_printf("%p\n", current);
}

t_stack	*new_node(int nb)
{
	t_stack	*node;
	
	node = malloc(sizeof(t_stack));
	node->content = nb;
	node->next = NULL;
	return(node);
}

int main(void)
{
// Stack A :
	t_stack *node1 = new_node(10);
	t_stack *node2 = new_node(5);
	t_stack *node3 = new_node(8);
	
	t_stack *node4 = new_node(150);
	t_stack *node5 = new_node(23);
	
	t_stack *node6 = new_node(43);
	t_stack *node7 = new_node(534);
	t_stack *node8 = new_node(2);
	t_stack *node9 = new_node(23);
	t_stack *node10 = new_node(19);
	t_stack *node11 = new_node(24);
	t_stack *node12 = new_node(17);
	t_stack *node13 = new_node(87);
	t_stack *node14 = new_node(94);
	t_stack *node15 = new_node(92);
	t_stack *node16 = new_node(76);
	t_stack *node17 = new_node(89);
	t_stack *node18 = new_node(43);
	t_stack *node19 = new_node(83);
	t_stack *node20 = new_node(33);
	t_stack *node21 = new_node(59);
	t_stack *node22 = new_node(95);
	t_stack *node23 = new_node(95);
	t_stack *node24 = new_node(71);
	t_stack *node25 = new_node(77);
	t_stack *node26 = new_node(16);
	t_stack *node27 = new_node(57);
	t_stack *node28 = new_node(98);
	t_stack *node29 = new_node(52);
	t_stack *node30 = new_node(66);
	t_stack *node31 = new_node(17);
	t_stack *node32 = new_node(55);
	t_stack *node33 = new_node(86);
	t_stack *node34 = new_node(65);
	t_stack *node35 = new_node(71);
	t_stack *node36 = new_node(40);
	t_stack *node37 = new_node(72);
	t_stack *node38 = new_node(57);
	t_stack *node39 = new_node(28);
	t_stack *node40 = new_node(68);
	t_stack *node41 = new_node(96);
	t_stack *node42 = new_node(22);
	t_stack *node43 = new_node(94);
	t_stack *node44 = new_node(64);
	t_stack *node45 = new_node(30);
	t_stack *node46 = new_node(13);
	t_stack *node47 = new_node(45);
	t_stack *node48 = new_node(70);
	t_stack *node49 = new_node(87);
	t_stack *node50 = new_node(96);
	t_stack *node51 = new_node(30);
	t_stack *node52 = new_node(41);
	t_stack *node53 = new_node(53);
	t_stack *node54 = new_node(67);
	t_stack *node55 = new_node(38);
	t_stack *node56 = new_node(44);
	t_stack *node57 = new_node(56);
	t_stack *node58 = new_node(72);
	t_stack *node59 = new_node(73);
	t_stack *node60 = new_node(55);
	t_stack *node61 = new_node(91);
	t_stack *node62 = new_node(30);
	t_stack *node63 = new_node(29);
	t_stack *node64 = new_node(66);
	t_stack *node65 = new_node(45);
	t_stack *node66 = new_node(39);
	t_stack *node67 = new_node(89);
	t_stack *node68 = new_node(34);
	t_stack *node69 = new_node(15);
	t_stack *node70 = new_node(99);
	t_stack *node71 = new_node(66);
	t_stack *node72 = new_node(44);
	t_stack *node73 = new_node(34);
	t_stack *node74 = new_node(64);
	t_stack *node75 = new_node(34);
	t_stack *node76 = new_node(23);
	t_stack *node77 = new_node(87);
	t_stack *node78 = new_node(12);
	t_stack *node79 = new_node(34);
	t_stack *node80 = new_node(67);
	t_stack *node81 = new_node(86);
	t_stack *node82 = new_node(34);
	t_stack *node83 = new_node(64);
	t_stack *node84 = new_node(12);
	t_stack *node85 = new_node(23);
	t_stack *node86 = new_node(45);
	t_stack *node87 = new_node(32);
	t_stack *node88 = new_node(24);
	t_stack *node89 = new_node(62);
	t_stack *node90 = new_node(37);
	t_stack *node91 = new_node(26);
	t_stack *node92 = new_node(14);
	t_stack *node93 = new_node(56);
	t_stack *node94 = new_node(63);
	t_stack *node95 = new_node(89);
	t_stack *node96 = new_node(95);
	t_stack *node97 = new_node(35);
	t_stack *node98 = new_node(1);
	t_stack *node99 = new_node(4);
	t_stack *node100 = new_node(8);
	node1->next = node2;
	node2->next = node3;
	
	node3->next = node4;
	node4->next = node5;
	
	node5->next = node6;
	node6->next = node7;
	node7->next = node8;
	node8->next = node9;
	node9->next = node10;
	node10->next = node11;
	node11->next = node12;
	node12->next = node13;
	node13->next = node14;
	node14->next = node15;
	node15->next = node16;
	node16->next = node17;
	node17->next = node18;
	node18->next = node19;
	node19->next = node20;
	node20->next = node21;
	node21->next = node22;
	node22->next = node23;
	node23->next = node24;
	node24->next = node25;
	node25->next = node26;
	node26->next = node27;
	node27->next = node28;
	node28->next = node29;
	node29->next = node30;
	node30->next = node31;
	node31->next = node32;
	node32->next = node33;
	node33->next = node34;
	node34->next = node35;
	node35->next = node36;
	node36->next = node37;
	node37->next = node38;
	node38->next = node39;
	node39->next = node40;
	node40->next = node41;
	node41->next = node42;
	node42->next = node43;
	node43->next = node44;
	node44->next = node45;
	node45->next = node46;
	node46->next = node47;
	node47->next = node48;
	node48->next = node49;
	node49->next = node50;
	node50->next = node51;
	node51->next = node52;
	node52->next = node53;
	node53->next = node54;
	node54->next = node55;
	node55->next = node56;
	node56->next = node57;
	node57->next = node58;
	node58->next = node59;
	node59->next = node60;
	node60->next = node61;
	node61->next = node62;
	node62->next = node63;
	node63->next = node64;
	node64->next = node65;
	node65->next = node66;
	node66->next = node67;
	node67->next = node68;
	node68->next = node69;
	node69->next = node70;
	node70->next = node71;
	node71->next = node72;
	node72->next = node73;
	node73->next = node74;
	node74->next = node75;
	node75->next = node76;
	node76->next = node77;
	node77->next = node78;
	node78->next = node79;
	node79->next = node80;
	node80->next = node81;
	node81->next = node82;
	node82->next = node83;
	node83->next = node84;
	node84->next = node85;
	node85->next = node86;
	node86->next = node87;
	node87->next = node88;
	node88->next = node89;
	node89->next = node90;
	node90->next = node91;
	node91->next = node92;
	node92->next = node93;
	node93->next = node94;
	node94->next = node95;
	node95->next = node96;
	node96->next = node97;
	node97->next = node98;
	node98->next = node99;
	node99->next = node100;
	t_stack **sa = &node1;


// Stack B :
	// t_stack **sb;



	ft_printf("before function\n");
	print_stack(sa, "sa");
	// print_stack(sb, "sb");
	// ft_rrr(sa, sb); // Changer le nom de la fonction a tester
	// printf("after function\n");
	
	// print_stack(sa, "sa");
	// print_stack(sb, "sb");
	return 0;	
}