
inherit ROOM;
void create()
{
  set ("short", "飯廳");
  set ("long","
    這是士兵們聊天吃飯的地方﹐雖然小了一點﹐但是該
有的東東還是有﹐果然是麻雀雖小五臟俱全﹐你看到旁邊
的打飯兵忙的不逸樂乎﹐一副欠打的樣子。

 ");
   set("exits", ([
   "north"   : __DIR__"r1.c",
   "west"    : __DIR__"r3.c",
  ]));      
  set("light_up", 1);
  setup();
} 
