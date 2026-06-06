// guard.c

#include <ansi.h>

inherit NPC;

string ask_me(object who);
int tt=2;
int done = 0;
void create()
{        
	set_name("貪財小劍童", ({ "money boy", "boy" }) );
	set("gender", "男性" );
	set("age", 11);
	set("str", 15);
	set("cor", 35);
	set("cps", 25);
	set("int", 15);
	set("long",
		"一位仙劍派的小劍童,他似乎得不到師長的喜愛.\n"
		"他手上提著大包小包,他現正進城來買辦.\n" );
        set("combat_exp",200);
	set("attitude", "peaceful");
	set("chat_chance", 10);
	set("chat_msg", ({
		"小劍童說: 唉! 有錢真好.\n",
		"小劍童說: 學劍真無聊.\n",
		"小劍童說: 掌門劍法獨步天下,還在蜀山設迷陣,真是無聊.\n",
	}) );
	set("inquiry", ([
		"money": " 你..你...你要給我嗎? \n",
		"錢": " 有錢能使鬼推磨,難到你沒聽過嗎?\n",
		"迷陣": "這是本門的密秘,你最好不要多問!!\n",
	]) );
        set_skill("parry", 5);
         set_skill("dodge", 5);
        set_skill("shasword", 2);
        map_skill("sword","shasword");
	setup();
	add_money("coin",100);
        carry_object("/open/gsword/obj/map1");
        carry_object("/open/gsword/obj/suit")->wear();
        carry_object("/open/gsword/obj/woodsword")->wield();
}
int accept_object(object who, object ob)
{   if(done)
   { return 1; }
   else {    
       if( ob->value() < 25 )
        {    say("貪財小劍童說: 就這麼一點啊?\n");
             return 1; }
        else { if( tt  <1 )
                 {  say("小劍童說: 哈哈,賺了真多錢,我就告訴你一個密秘吧!!\n" 
                        + "          迷陣只要走 金木土水火 就可以通過了.\n");   
                    set_name("癩皮狗",({"urgly dog","dog"}));
                    set("inquiry", ([
                           "錢": "汪汪!!",
                                   ]));
                    set("long","一隻醜陋的癩皮狗,身上滿是膿胞和跳蚤.");
                    set("chat_msg", ({
                           "小狗嗚噎:...汪...汪...汪...\n",
                           "小狗哀鳴:...嗚...嗚...嗚...\n",
                           }));
                    message("vision",
                             HIY + " 突然, 貪財小劍童大叫: 饒了我,師父!! 師父!!\n"
                             " 你見到一陣黑霧隴罩著貪財小劍童.\n"
                             HIR + " 你簡直不敢相信,貪財小劍童化為一隻狗 !!!\n" + NOR,
                             environment(), this_object() );
                   done =1 ;          
                } else {                                   
                    say("貪財小劍童說: 謝謝你了,再給一點吧!!\n");
                    tt--;  }
             return 1; }
             }
}                 	

