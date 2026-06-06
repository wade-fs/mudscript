
inherit ROOM;
void create()
{
  set ("short", "小通舖");
  set ("long","
    這一個通舖比之前的還小﹐但是還算整潔啦﹐這裡可
能就是將領們所睡的地方﹐在這還有人守衛著﹐莫非這裡
有啥祕密嗎..在你面前還有個大大的圓桌(table),上面擺\
\了\一些雜七雜八的東西。

 ");
   set("exits", ([
   "east"   : __DIR__"r26.c",
   
  ]));
  set("item_desc", ([ /* sizeof() == 2 */
  "table" : "一面巨大圓桌，在上面中有一座神像(god)看看吧。。。\n",
  "god"   : "神像說道:看誰像誰,誰看誰,誰都得像誰～\n",
  ]));
  set("light_up", 1);
  setup();
} 

