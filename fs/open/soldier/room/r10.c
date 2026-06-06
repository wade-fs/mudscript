
inherit ROOM;
void create()
{
  set ("short", "地道口");
  set ("long","
    這邊是反亂軍隊所出入的地方﹐不過當然一個組織
的地方怎麼可能只有一個出入口﹐在你兩旁個有一座聖
火﹐在這裡右方好像有點動靜。

 ");
   set("exits", ([
   "east"       : __DIR__"r9.c",
      
  ]));      
  set("light_up", 1);
  setup();
} 

