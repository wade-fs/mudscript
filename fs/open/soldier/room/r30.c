
inherit ROOM;
void create()
{
  set ("short", "大澡堂");
  set ("long","
    稀哩嘩啦的聲音一堆﹐原來這裡是大澡堂﹐在旁邊衣
物架中還堆滿了一些內衣褲在你旁邊還有人在趕著洗澡﹐
好像趕著要做啥事一樣﹐更裡面那間還有人在唱歌咧﹐聽
了就想過去殺死他咧。

 ");
   set("exits", ([
   "north"   : __DIR__"r25.c",
   "west"    : __DIR__"r31.c",
   
  ]));      
  set("light_up", 1);
  setup();
} 

