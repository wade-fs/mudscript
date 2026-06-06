#include <weapon.h>                           
#include <ansi.h>

inherit LANCE;
void create()
{           
           seteuid(getuid());
  set_name("水影",({"Water-shadow","shadow"}));
           set_weight(15000);
           if( clonep() )
 set_default_object(__FILE__);
           else {
                   set("unit", "把");
           set("long","傳說中水神為了打倒魔界頭頭的兒子,將自己的血做出一個
           強力魔法陣,他在結界裡花了七七四九天塑造而成,造出來時他已身心俱疲
           無力再戰,他使出全力把槍丟出去並大喊水影去找一位能打倒他的人吧..,
           ...\n");
                   set("value",3500);
                   set("material", "gold");
           set("wield_msg", "$N舉起$n,你感覺你的力量被$n抽走了,槍身並發出強
           烈的光。  .\n");
           set("unwield_msg", "$N放下$n,$N感覺輕鬆多了。.\n");
           }
           init_lance(40);
           setup();
           }






