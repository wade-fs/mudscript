#include <weapon.h>
  inherit ITEM;
void create()
{
	set_name("血麒麟", ({ "red-kylin","kylin" }) );
  set("unit","個");
  set("long", @LONG

	破邪洞窟中最恐怖的怪獸, 全身如火炎般通紅. 一般的高手
	碰上牠非得喪命不可!!其身上的鐵鍊是聖火教教主每次練功
	後所加上去的. 算算鐵鍊共有十數條, 可見聖火教教主的武
	學造詣非常之高, 匪夷所思!!

LONG);
  set("no_get",1);                    
	setup();
}
