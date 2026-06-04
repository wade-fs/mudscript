// concentrate.c
// by airke
#include <ansi.h>

int exert(object me, object target)
{
int atman_gain,forcelost;

if( target!=me) return 
notify_fail("「聚靈法」只能用來恢復自己的靈力。\n");

if( me->query("force") < 10 ) 
return notify_fail("你的內力不夠。\n");

if( me->query("atman") >= me->query("max_atman") * 8 && me->query("class")=="dancer" ) 
return notify_fail("你的靈力已經到達極限。\n");
	
atman_gain =me->query_skill("force")*2;

// if( atman_gain + me->query("atman") > me->query("max_atman") )
// me->set("atman", me->query("max_atman"));
// else
   me->add("atman",  atman_gain);
   me->add("force", -10);
// me->receive_damage("gin", 10);

  message_vision(HIY + "$N靜走了下來﹐心神合一﹐緩緩的運起「聚靈法」...\n" + HIR + "一股靈氣從四周的環境飄來散出﹐匯聚在$N的天靈﹐然後慢慢逝去。\n" + NOR,me);
  if( me->query("atman") > me->query("max_atman") * 8 && me->query("class")=="dancer" ) 
  {
  write("當你的靈力增加的瞬間你忽然覺得腦中一片混亂，似乎靈力的提昇已經到了瓶頸。\n");
  me->set("atman", me->query("max_atman")*8);
  }
  if( me->query("atman") > me->query("max_atman") * 4 && me->query("class")!="dancer" ) 
  {
  write("當你的靈力增加的瞬間你忽然覺得腦中一片混亂，似乎靈力的提昇已經到了瓶頸。\n");
  me->set("atman", me->query("max_atman"));
  }
  if( me->is_fighting() ) me->start_busy(3);
 return 1;
}

