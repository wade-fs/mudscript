// guard.c

#include <ansi.h>

inherit NPC;

string ask_me(object who);
int counter = 1;
void create()
{
	set_name("潦倒劍客", ({ "sworder", "man" }) );
	set("gender", "男性" );
	set("age", 41);
	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 5);
	set("long",
		"一位從東北來的劍客,他抱著滿腹的希望想向無極真人學劍.\n"
		"他的盤纏用完了,正躊躇不知如何是好,你想你可以資助他.\n" );
	set("combat_exp",893);
	set("attitude", "peaceful");
	set("chat_chance", 10);
	set("chat_msg", ({
		"潦倒劍客說: 沒想到要見無極真人如此困難.\n",
		"潦倒劍客說: 天下第一高手無極真人,我只要學得其十分之一劍術,就足以獨霸武林了.\n",
	}) );
	set("inquiry", ([
		"help": "謝謝你...我只是欠些錢而已...\n",
		"資助": "$$$$...一毛錢逼死一條好漢...\n",
	]) );
	set_skill("sword", 25);
	set_skill("parry", 30);
	set_skill("dodge", 35);
	setup();
	add_money("silver",4);
        carry_object("/open/gsword/obj/robe_1")->wear();
        carry_object("/open/gsword/obj/boot-1")->wear();
        carry_object("/open/gsword/obj/sword")->wield();
}
int accept_object(object who, object ob)
{       object book;
        if(counter)
        {  
          if( ob->value() < 500 )
          {    say(" 潦倒劍客說: 謝謝你,等我成名後會記得你的.\n");
              return 1; }
          else {  say(" 潦倒劍客說: 真是太感謝了,這本書給你算是回報.\n");
               book = new("/open/gsword/obj/sword_book");
               book->move(this_player());
               counter = 0;
               return 1; }
         } else {
               say(" 潦倒劍客說: 謝謝你了,我的錢夠用了...\n");
               return 1; }      
}                 	

