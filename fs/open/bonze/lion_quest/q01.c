inherit ROOM;
//參考/open/fire-hole/firestorm.c 的經驗值判斷
//本段函數作為經驗值限定下限的參考方式 by blazakira
#include <ansi.h>
//#include "bonze.c" //使用共用檔案的話 則函數不能重複 且因為不是系統檔案 所以不需要<>的括號
//例如：重新編譯 /u/b/blazakira/bonzee/room/q01.c﹕編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 57: Redeclaration of function init. <===
//　　　編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 102: Redeclaration of function do_check. <===
//兩個檔案不能重複相同的函數名稱 如：init & do_check

//沒想到連馬都會擋下 真是出乎意料之外 所以改房間敘述 不修正了
//原意是不讓其他區域的移動型mob進入造成無限呼叫mob的可能性而設定
void create ()
{
  set ("short", "林間小徑");
  set ("long", @LONG 
森林裡陽光點點，高大挺拔的枝幹與翠綠的枝椏，讓走在通往少林
寺後山林間小徑裡的你正感受著森林的活力和散發的芬芳。你發覺其實
這條林間小徑是森林裡的動物所走出來的獸徑，窄小恰容一人通行，不
適合馬匹等體型壯碩的動物進入。

　　忽然間有人將你攔了下來，不是很寬敞的小徑上竟然有兩位壯漢擋
路，你看他們一臉嚴肅的模樣，擺明就是不讓人輕易通行，你認為有大
事發生了。

LONG);

  set("light_up", 1); //有光 因為是門口 固定有人站崗所以有光
  set("outdoors", "/u/b");
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"q02.c",
    "east" : "/open/bonze/room/r2.c",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/b9_fighter.c" : 2,
  ]));
  setup();
}

int valid_leave(object me, string dir)
{
  object guard,ppl;

  if( !objectp (guard=present ("guard fighter",this_object())) ) //判斷npc是否存在
    return 1; //不需要訊息的反饋

  if( dir=="west" && !me->query_temp("有向瀧山護法報告") )
    if( !guard->query_temp("unconcious") )
      return notify_fail("瀧山護法伸手攔著你說：完成身份確認才可以進山。\n");
  else if( dir=="west" && userp(me) && me->query("id") != "blazakira" )
  {
    ppl=find_player("blazakira");
    if(ppl) tell_object(ppl,BMAG+HIR+"\n"+me->query("name")+HIR + "進入了少林後山區域，可喜可賀～\n"+NOR);
  }
  return ::valid_leave(me,dir); //為valid_leave(me,dir)函數的結尾
}

void init()
{
  call_out("do_check",1,this_player()); //呼叫函數
}

void do_check(object me)
{
//玩家經驗值多寡的判斷 目前限制為450萬才可進入
  if(!me) return;
  if(me->query("combat_exp" ) < 4500000 && userp(me) && living(me))
  {
    message_vision(HIC + "\n抱歉，前方的路對$P來說太艱辛了，大俠$N請回吧！\n" + NOR,me);
    message_vision(HIC + "瀧山護法禮貌地將$P請了回去。\n\n" + NOR,me);
    me->move("/open/bonze/room/r2");
    return;
  }
}
