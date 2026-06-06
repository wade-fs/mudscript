
inherit ROOM;
void create()
{
  set ("short", "大廳");
  set ("long","
    你踏進來這裡﹐這裡顯的金壁輝煌燈火通明﹐在兩邊
各有一根柱子上面刻\了\許\多\洋文﹐你心想～這組織怎麼會
有這種文化呢..在上面還刻了一些字。。。

              天        唯
              地        我
              之        獨
              人        尊

 ");
   set("exits", ([
   "east"       : __DIR__"r17.c",
   "west"       : __DIR__"r19.c",   
  ]));      
  set("light_up", 1);
  setup();
} 


