
inherit ROOM;
void create()
{
  set ("short", "大通舖");
  set ("long","
    這邊已經算是反亂軍們睡的地方了由於經費不足所以
大伙睡的地方擠了點﹐在這裡以依稀可以聽到水稀稀的聲
音﹐在你旁邊有扇門漏出一點光線﹐地上還濺初一灘水出
來﹐過去看看有啥好看的吧。

 ");
   set("exits", ([
   "south"   : __DIR__"r30.c",
   "west"    : __DIR__"r26.c",
   
  ]));      
  set("light_up", 1);
  setup();
} 
