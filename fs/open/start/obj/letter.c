// /open/start/obj/letter.c by oda

#include <ansi.h>
#include "../start.h"
#include <room.h>

inherit ITEM;

void create()
{
	set_name("村長的信",({"sheik's letter", "letter"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","這是凌雲村長托你幫他送的信，裡面不知道寫了些什麼。\n");
	set("unit","封");
	}
	setup();
}

void init()
{
	add_action("do_read", "read");
}

int do_read(string arg)
{
	object who;
	who = this_player();

	if( !arg || arg!="letter" )
		return notify_fail("你要讀什麼？\n");
	if( !who->query_temp("reading") ) {
		who->set_temp("reading", 1);
		return notify_fail("你突然想起村長交待的話，開始猶豫了起來。\n到底該不該看呢？....\n");
	}

/*
	if( who->query_temp("letter")==1 ) {

		switch( random(2) ) {
			case 0:
			write("\n
	老王：
	    我把錢都藏在村子南邊的稻田裡，你趁晚上沒人的時候
	去偷偷把它挖出來，就不會被人發現了。記住，錢藏在一個
	稻草人附近，你去那裡找一找(search)就知道了。\n\n");
			tell_object("為了避免村長他們發現信被偷看了，你小心翼翼的將信\n折好收了起來，準備先把信送去再回來拿錢。\n");
			who->set_temp("letter", 3);
			break;

			case 1:
*/
			write("\n
	老王：
	    我把錢都藏在....

你發現似乎這是一封藏寶圖，正興奮的準備往下讀時....\n\n");
			call_out("do_read2", 3, who);
/*
			break;

		}
*/

		return 1;
/*
	}
	else if( who->query_temp("letter")==3 )
		return notify_fail("還看！不怕被發現啊？快去送信吧。\n");
	else
		return notify_fail("別人的信還不要亂看比較好吧。\n");
*/
}

int do_read2(object who)
{
	int i;

	tell_object(who,HIY"想活命的話就乖乖把信留下！\n\n"NOR);
	tell_object(who,"不知何時，你已經被一群凶神惡煞的土匪給團團圍住了....\n\n");
	for(i=0; i<2; i++)
		new(S_NPC"bandit")->move(environment(who));
/*
	tell_object(who,CYN"山賊頭子冷冷的說道：小子，我們注意凌雲村那個老頭已經很久了，今天總算給我逮到機會....哈哈哈哈哈！\n"NOR);
	tell_object(who,CYN"山賊頭子看著你說：哼哼....交出你身上的錢跟信就饒你一命！\n"NOR);

	if( who->can_afford(1000)!=1 ) {
		tell_object(who,CYN"山賊頭子破口大罵：臭小子，連點錢都沒有。兄弟們，給我打！\n"NOR);
		who->set("gin", 20);
		who->set("kee", 20);
		who->set("sen", 20);
		tell_object(who,"\n你被山賊痛毆一頓以後，總算是保住了一條小命....不過信已經被搶走了。\n");
	}
	else {
		who->pay_money(1000);
		tell_object(who,"\n山賊搶了你的信和一千文錢以後便長揚而去了。\n");
	}

	tell_object(who,"你開始後悔自己不該偷看信的....\n");
	destruct( this_object() );
*/
	return 1;
}
