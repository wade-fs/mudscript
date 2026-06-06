#include <ansi.h>
#include "/open/open.h"
inherit F_VENDOR;
int done = 0;
void create()
{
	set_name("客棧老闆",({"keeper"}));
	set("long","蜀中客棧的老闆,他對你愛理不理的.你可以看看他有在賣甚麼(list).");
	set("gender","男性");
	set("combat_exp",2000);
        set("age",25);
	set("str", 30);
        set("cor", 30);
	set("con", 30);
	set("vendor_goods", ({
	    COMMON_OBJ"pill2",
            "/obj/example/wineskin",
            "/obj/example/dumpling",
        }) );
        set("inquiry",([
            "展伯承" : "就是那個掉了東西還要怪別人的小子?\n",
            "搜索令" : "呵呵...你還想我會告訴你怎麼搜我房子嗎?...少呆了...\n",
            "名畫" : "喔...你別聽那小子亂講,本店可是規規矩矩作生意的.\n",
            ]) );
        set_skill("dodge",30);
        set_skill("unarmed",60);
	set_skill("dagger",20);
        set_skill("parry",30);
	setup();
        carry_object("/obj/example/dagger.c")->wield();
        carry_object("/open/gsword/obj/robe")->wear();
             carry_object("/open/gblade/obj/picture");
        
}
void init()
{
  ::init();
  add_action("do_show","show");
}

int accept_fight(object who)
{
   return notify_fail("老闆不願與你動手.\n");
}

int accept_kill(object who)
{
   return notify_fail("老闆不願與你動手.\n");
}
      
int accept_object(object me,object ob)
{  
  if(ob->query("id") != "su_note")
  {
    command("say 謝了,不過我不需要.\n ");
    return 1;
  }
  write("老闆臉色突變.\n");
  command("say 哼...量你也搜不出甚麼來!!!\n");
  me->set_temp("have_note",1);  
/*  command("say 搜索令??? 要搜我的店,拿你命來換!!!\n ");
  if(done)
       return 1;
  done = 1;
  kill_ob(me);
*/  
  return 1;  
}
  
int do_show(string arg)
{ 
  object me;
  me=this_player();
  if(me->query_temp("see_blood"))
  {
    write("老闆說: 你還知到甚麼??...看來...饒不得你了!!!\n");
    kill_ob(me);
  }  
  else
    write ("看什麼看啊!\n");
  return 1;
}     
