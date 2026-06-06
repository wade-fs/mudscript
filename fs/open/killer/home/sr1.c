#include <room.h>
inherit ROOM;
void create()
{
set("short", "殺手宿舍");
  set ("long", @LONG
這裡是極為平凡的地方，一眼望去，似乎沒有一點像睡覺的地方。
這是屬於殺手的特殊設計，為了怕睡覺時被暗殺，所以你一般是看不到睡覺的人。
必定隨時都有人在守衛著，所以你想趁機殺了熟睡中的人是不可能的。
不過這裡似乎守衛不夠森嚴人少了一點，真是奇怪，難道有人跑去摸魚？

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"sr0.c",
"north" : __DIR__"sr2.c",
]));
  setup();
}

void init()
{
  object ob2;
  ob2=this_player();

  add_action ("do_search","search");

  if (!interactive(ob2)) return ;

  if (ob2->query_temp("rain_4")==1)
  {
   tell_object(ob2,"根據柴榮的敘述，你發現了往地下一樓的密道\n"); 
   tell_object(ob2,"你在看了，四周無人後，立刻往開啟密道，往密道翻去\n");
   ob2->move(__DIR__"underm.c");
  }
}

int do_search ()
{
  object me,ob;

  me=this_player();
  if(me->query_temp("diray")==1)
  {  
   tell_object(me,"因為葉秀殺日記內容所述，你四處的尋找，居然發現了鑰匙\n");
   tell_object(me,"正當你很高興地拿取鑰匙之時，不小心觸動機關，落入陷阱\n");
   if (me->query("class") != "killer")
   {   
       me->move(__DIR__"doorm.c");
       return 1;    
   }
   me->move(__DIR__"sdr1");
/*   ob=new("/open/killer/obj/key_d.c");
   ob->move(me);   */
   me->set_temp("key",1); 
   return 1;
  }
  return 0;
}
