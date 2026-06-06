#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "紅葉組密室");
set("long", @LONG
	你似乎來到了一個詭異的地方，陰暗的燈光顯示出這裡隱密程度
	你略為環顧了一下四周，想不到居然沒有任何出口？
	想不到殺手總壇居然還有這樣子的地方，莫非有隱藏著什麼樣的秘密？
	到處搜尋一下， 應該可以找到一些蛛絲馬跡吧......

LONG
);
setup();
}

void init()
{
  add_action("do_search", "search");
}

int do_search(string arg)
{
  object me=this_player();
  int max;

  if (arg)
  	return 0;
  if (me->query_temp("firstpart")  !=2)
  {
    message_vision(HIY"$N哇勒....你是怎麼來到這裡的，作弊呀？？  可惡........。\n"NOR, me);
    message_vision(HIY"一瞬間一陣機關鳴動聲............\n"NOR,me);
    max=me->query("kee");
    max= (int) (max/2);
    me->add("kee",-max);
    tell_object(me,HIR"一陣衝撞力將你彈飛，落入陷阱之中一直墜落～～\n"NOR);
    me->move("/open/killer/room/firstrm.c");
    return 0;
  }
  else
  {
    message_vision(CYN"$N在四周尋找了一下，發現了一個按鈕，用力的按了下去\n"NOR, me);
    message_vision(CYN"一陣機關鳴動聲後，牆上突然出現一個暗門，裡面竟然是魯尋!!？\n"NOR,me);
    message_vision(CYN"你將魯尋身上的枷鎖解開之後，並且解開他的穴道。\n"NOR,me);
    message_vision(CYN"$N將魯尋救出來後，詢問有關東瀛島的所在問題.....\n"NOR,me);
    tell_object(me,HIY"魯尋說：『上次我們去找我爹的夢想得時候，就發現往東瀛方向的風浪過大』\n"NOR);
    tell_object(me,HIY"『所以才會被吹到那作海盜島上，似乎是因為島的西北方往東瀛的航道上』\n"NOR);
    tell_object(me,HIY"『有一陣強力的神風阻擋，所以根本無法接近該區域』\n"NOR);
    tell_object(me,HIY"『但是我爹或許\會知道(破浪的方法)，你可以前去詢問他』\n"NOR);
    tell_object(me,HIY"『後面有一個密道，是東瀛殺手的出入口，你快離開...，我會自己走的』\n"NOR);
    me->set_temp("firstpart",3);
    me->move("/open/killer/room/firstrm.c");
    return 1;
  }   
 }
