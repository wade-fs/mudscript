// Room: /open/bonze/room/k01.c
//調整為少林挑水quest相關 by blazakira 2010/11/11

#include "bonze.c"
inherit ROOM;
void create ()
{
  set ("short", "伙房");
  set ("long", @LONG
這裡是少林寺的伙房，為了應付少林寺龐大的人口，到處都是特大
號的煮飯工具。伙房師父忙進忙出的，手上拿著各式的工具開始開伙，
如果少林弟子有需要的話，還可以跟這些師父要吃的。
LONG);

  set("objects", ([ /* sizeof() == 1 */
//  "/open/bonze/npc/k_monk" : 1,
  BONZE_NPC"k_monk.c" : 1,
  BONZE_OBJ"vat.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"k01.c",
  "south" : __DIR__"k08.c",
]));
  set("no_magic", 1);
  set("no_fight", 1);
  set("light_up", 1);
  setup();
}

void init()
{
  object me=this_player();
  int i;
  i=random(6)+1;
/*
魚缸@台北 說 (下午 04:47):
先在外面設一個 int need_clone = true;
魚缸@台北 說 (下午 04:47):
然後if(!clonep(ob2)) need_clone = false;
魚缸@台北 說 (下午 04:47):
if(need_clone == true) { clone....}
或是
foreach( object ob2 in children之後
if(sizeof(children(file))  < 2)
children( file)
他是只有一個
*/
//  foreach( object ob2 in children(BONZE_NPC"k_monk3.c") ) {
    if(sizeof(children(FQ_NPC"k_monk3.c")) < 2) { //二廚不存在時 呼叫一隻出來
/*
魔女洋子(建彰： 說 (下午 06:41):
if(sizeof(children(FQ_NPC"k_monk3.c")) < 2) { //二廚不存在時 呼叫一隻出來
魔女洋子(建彰： 說 (下午 06:41):
奇怪 不是應該< 1時嗎?
魚缸@台北 說 (下午 06:42):
這有點復雜XD
魚缸@台北 說 (下午 06:42):
物件被呼叫時
魚缸@台北 說 (下午 06:42):
他會先把該檔案先讀進記憶體
魚缸@台北 說 (下午 06:42):
然後再copy 一份到你現在的位置
魚缸@台北 說 (下午 06:42):
這樣會變成2
魚缸@台北 說 (下午 06:44):
你可以用 printf(("%O",children(xxxx))
魚缸@台北 說 (下午 06:44):
會看到有2個物件
魚缸@台北 說 (下午 06:44):
後面有#數字的
魚缸@台北 說 (下午 06:44):
就是 copy 出來的
*/
//      if(clonep(ob2)) {
        new(FQ_NPC"k_monk3.c")->move(BONZE_ROOM"k0"+i);
        if( wizardp(me) )
        {
          message_vision("現在二廚人在k0"+i+"的房間。\n",me);
        }
//      }
    }
//  }
}

//南方房間為可攻擊區域所以不給大廚走過去
int valid_leave(object me, string dir)
{
	if (dir=="south" && me->query_temp("quests/bonze/stop")) //如果要往south離開 且 有mark ("quests/bonze/stop") 時 阻擋之!
//	if(!wizardp(me))
		return notify_fail("STOP!\n");
	return 1;
}
