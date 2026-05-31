//加入劍魔轉回仙劍的解謎要素 by Alucard 2009/08
inherit ITEM;
#include <ansi.h>
void create()
{
set_name("血魔殘集", ({ "bloodbook","book" }));
set_weight(100);                                                                
if( clonep() )                                                                  
set_default_object(__FILE__);                                                   
else {                                                                        
set("unit", "本");                                                             
set("long",
    "這是血魔練劍的記事本, 上面有許\多人形圖案, 跟你所學武學幾乎完全不同
看情形是很難領誤的...\n"); 
set("value", 10);                                                               
   set("no_drop", 1);
   set("no_give", 1);
   set("no_get", 1);
   set("no_auc", 1);
set("material", "paper");                                                      
set("skill", ([                                                      
"name": "blood_sword",                                                         
              "sen_cost":     600,
              "difficulty":   55,
              "max_skill": 99,                                               
// from this object.                                                                                
]));
        setup();
}
}
int query_autoload()
{
  object player;
  if(!environment()) return 0;
  if(!living(environment())) return 0; 
 
  player=environment();
if(player->query("family/family_name") == "血魔一派" && player->query("bloodsword") > 1)
    return 1;
  else 
  return 0;
}

void init() {
  add_action("do_study","study");
  //::init();
}

int do_study()
{
  object me = this_player();
  if(me->query_temp("quest/return_sha"))
  {
  message_vision(HIR"$N已下定決心返回師門，因此立即闔上書本，當作自己看不懂。\n"NOR,me);
  return 1; 
  }
} 
