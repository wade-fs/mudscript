// 修改cmd search.c by nike
//更改尋找的訊息 以免遺失訊息給玩家 by blazakira 2011/11/6

#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;

int search(object me);

int main(object me)
{
  object room = environment(me);

  if(!me) return 1;
  if(me->query_skill("godcure",1) < 100 )
    return notify_fail("你對藥理尚不夠熟悉，搜索不到藥材!!\n");
  if(!room->query("can_search",1))
    return notify_fail("你的直覺告訴你此處不可能能找到任何藥材，不必浪費時間了!!\n");
  if(me->query("class") !="doctor" )
    return notify_fail("你不是醫生不知如何搜尋藥材!!\n");
  if(me->query_temp("search") ==1  )
    return notify_fail("你正在尋找藥材!!\n");
  if(me->is_fighting() || me->is_busy())
    return notify_fail("戰鬥中無法搜尋藥材!!\n");

  message_vision(HIB + "$N開始四處搜尋藥材!!\n" + NOR,me);
  me->start_busy(2);
  me->set_temp("search",1);
  call_out("search",5,me);
  return 1;
}

int search(object me)
{
  object obj;
  int i = random(120);

  seteuid(getuid());
  if(!me) return 1;
  if(i > 0 && i <= 3) {obj = new("/open/doctor/item/sky_item.c");}
  if(i > 5 && i <= 8)  {obj = new("/open/doctor/item/ground_item.c");}
  if(i > 10 && i <= 13)  {obj = new("/open/doctor/item/human_item.c");}
  if(i > 15 && i <= 20)  {obj = new("/open/doctor/item/bilin_item.c");}
  if(i > 22 && i <= 27) {obj = new("/open/doctor/item/f_item.c");}
  if(i > 29 && i <= 35) {obj = new("/open/doctor/item/ff_item.c");}
  if(i > 38 && i <= 44) {obj = new("/open/doctor/item/g_item.c");}
  if(i > 50 && i <= 57) {obj = new("/open/doctor/item/icetree_item.c");}
  if(i > 64 && i <= 72) {obj = new("/open/doctor/item/nine_item.c");}
  if(i > 79 && i <= 89) {obj = new("/open/doctor/item/seng_item.c");}
  if(i > 93 && i <= 100) {obj = new("/open/doctor/item/sick_item.c");}
  if(i > 105 && i <= 112) {obj = new("/open/doctor/item/taii_item.c");}
  if(obj)
  {
//    message_vision(HIY + "$N費盡了心力，終於找到了一株$n！\n" + NOR,me,obj);
    message_vision(HIY + "$N費盡了心力，終於找到了一株"+obj->query("name")+"！\n" + NOR,me);
    obj->move(me);
    me->delete_temp("search");
    return 1;
  }
  else
  {
    message_vision(HIY + "$N努力的找了半天，還是沒找到任何藥材！\n" + NOR,me);
    me->delete_temp("search");
    return 1;
  }
}
