

inherit ROOM;
void create()
{
  set ("short", "圓環梯");
  set ("long","
    你不經意的來到這..往下看下去是一座蠻長的圓環梯
﹐在這裡旁邊點滿了聖火一路的聖火點亮了整個地道不知
道往下走會發生什麼事情﹐如果現在想跑路還可以勞跑﹐
如果神勇的話舊往下衝吧。

 ");                                  
   set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"r23.c",
  "westdown" : __DIR__"r34.c",
]));
  set("no_magic", 1);
  set("no_transmit", 2);
  set("light_up", 1);
  setup(); 
 
}
int valid_leave(object me, string dir)
 {
   if(dir=="out"&&present("lo",environment(me))) 
   {
    if(!me->query_temp("allow-out"))
    return notify_fail("阿諾啥米碗糕喊道: 想出去門都沒有～
先過我這關吧!!\n");
   }
  return 1;
 }

  
 
 

