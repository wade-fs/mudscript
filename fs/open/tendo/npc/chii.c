#include <ansi.h>
inherit NPC;


string do_give();
string do_give2();
void do_book(object who);

void create()
{
	set_name("筑依",({"chii"}) );
        set("long","一位青春年華的少女，衣著樸素，平實中帶著幾分俏麗。\n");
        set("gender","女性");
        set("class","taoist");
        set("combat_exp",5000);
        set("attitude","friendly");
        set("age",16);
	 set("title","天道派第三代弟子");
        set("str", 25);
        set("cor", 30);
        set("cps", 30);
        set("per", 30);
        set("spi", 30);
        set("int", 26);
        set("force", 200);
        set_skill("literate",100);
        set("max_force", 200);
        set("max_mana",200);
        set("max_atman",150);
        
        set("force_factor", 6);

	set("inquiry",([
	"易經" : (:do_give:),
	"老莊" : (:do_give2:),
	]));
        setup();
	add_money("silver",3);
}

string do_give()
{
  object who=this_player();
  if(who->query("class")=="taoist") {
     call_out("do_book",4,who);
     return "易經是嗎?....你等會兒，我去找一下..\n";	
 }
 return "嗯....對不起，你不是天道的弟子不能給你。";  
}

string do_give2()
{
  object who=this_player();
  if(who->query("class")=="taoist") {
     new("/open/tendo/obj/book2")->move(who);
     return "筑依給了你一本道德經。\n";	
 }
 return "嗯....對不起，你不是天道的弟子不能給你。";  
}


void do_book(object who)
{
  message_vision ("過了一會，筑依交給$N一本厚厚的書冊。\n\n",who);
  message_vision ("筑依笑著說道: 如果不見了，可以再來找我要..:)  \n",who); 
  new("/open/tendo/obj/book")->move(who);
  return;
}
