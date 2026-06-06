#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
  set_name("仙劍的老長工", ({ "an old worker", "worker" }) );
        set("long","瞧他一副熟練的樣子 ,好像從小就已經在這打掃至今了\n");
        set("gender", "男性" );
        set("class","swordsman");
        set("age", 75);
                set("str", 44);
                set("cor", 24);
                set("cps", 18);
                set("per", 24);
                set("int", 42);
	set("force",100);
        set("max_gin",100);
        set("force_factor",3 );
        set("gin",100);
        set("max_kee",2000);
        set("kee",2000);
        set("max_mana",100);
        set("mana",100);
        set_skill("force",40);
        set_skill("dodge",60);
        map_skill("dodge","sha-steps");
        set_skill("sword",60);
        map_skill("force","shaforce"); 
        set_skill("unarmed",90);
        setup();
        }
 void init()
  { 
   add_action("do_search","search");
   add_action("do_answer","answer");
   }
  int do_search(string arg)
  {
   object who;
    who=this_player();
    if( !who->query_temp("allow_read",1))
       return notify_fail("你尚未經過掌門與許 ,怎可擅自進來藏經閣翻閱密笈 ,快出去!!\n");
    if( arg!="shelf")
      return 0;
    else
     {
     message_vision("長工問道 : 你在找什麼 ?? 可以告訴(answer)我嗎 ??說不定我
       可以幫上忙.\n",who);
      who->set_temp("have_search",1);
      return 1;      
     }
    }
  int do_answer(string arg)
   {
  object who;
    who=this_player();
    
    if(!who->query_temp("have_search",1))
      return notify_fail("你在作什麼??\n");
    if( arg!="仙劍密笈")
     return notify_fail("長工說道 : 我不能幫上忙 ,真是抱歉了\n");
    else
     {
      message_vision("長工說...聽說當初綠毛老祖大鬧仙劍之後,這本秘笈也就跟著失蹤了,
             而在老祖被逍遙子制伏之後,只得到一把赤麟之劍,而秘笈也不知所蹤了.\n",who);
   return 1;
      who->delete_temp("have_search",1);
      who->set_temp("have_answer",1);
      } 
    }          
