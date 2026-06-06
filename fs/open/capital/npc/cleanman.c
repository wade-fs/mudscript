//made by smirk
#include <ansi.h>

inherit NPC;

void create(){
	set_name("清道夫",({"clean man","man"}) );
	set("gender","男性");
	set("age",42);
	set("long",@LONG
	一位清早起床打掃環境的清道夫
LONG);
	set("combat_exp",2000);
	set("attitude","friendly");
	set("str",28);
	set("int",18);
	set("per",15);
	set_skill("dodge",20);
	set_skill("parry",10);
	set("chat_chance",30);
	set("chat_msg",({
	"清道夫說道:早睡早起身體好!!\n",
	"清道夫說道:身體是要好好保養的,像我40歲還是一條活龍,就是因為*保養*有方\n",
	"清道夫說道:每天都有清不完的垃圾,真麻煩!!\n",
	(: this_object(),"around" :),
        }) );
	set_temp("apply/armor",10);
	  set("inquiry", ([
	  "thief" : "你是說那個最近在皇城惡名昭彰的大盜是吧?!
                     可惜我連影子都沒看過,一定是位高人,能夠飛簷走壁說!!\n",
	  "保養"  : "這保養的方法(method)可是我縱橫京城的祕寶!!",
	  "method": "方法就是早睡早起嘛!!........什麼!!想知道祕技?!",
	  "祕技"  : "你真想知道就付點代價吧!!這可是我吃飯的傢伙咧",
	  "代價"  : "嘿嘿....不二價....10兩黃金!!",
	  ]) );	
setup();
	carry_object("/open/capital/obj/broom")->wield();
	carry_object("/obj/cloth")->wear();
	carry_object("/open/capital/obj/workpants")->wear();
	add_money("/obj/money/silver",20);
}

int accept_object(object who,object ob)
{  
  if( ob->value() < 1000000 )
   { say("清道夫說道:你太小看我的祕技了吧!!\n");
	return 1;}
  else{
    message_vision("清道夫說道:嘿嘿,果然你是個明眼人,來....這顆靈丹給你!!\n",who);
    new("/open/capital/obj/ggpill")->move(who);
    	return 1;}
}	
