#include <ansi.h>
#include <weapon.h>
inherit STAFF;
object user=this_player();
int kar;
void create()
{
     seteuid(getuid());
     set_name(HIC"榴槤杖"NOR,({"durian staff","staff"}) );
     set_weight(2000);
     if( clonep() )
     set_default_object(__FILE__);
     else {
            set("long","杖身籠罩著消消藍氣，散發出陣陣臭味。\n");
            set("unit", "把");
            set("value",100000);
            set("material","blacksteal");
            set("weapon_prop/staff",10);
            set("no_give", 1);
            set("no_sell", 1);         
            set("no_auc",  1);
            set("no_drop", 1);
            set("no_auc",  1);
            set("no_put",  1);
        set("no_get", 1);
                        set("wield_msg",HIW"$N將內力貫入杖身，"HIC"榴槤杖"HIW"感應到$N"HIW"的感召，發出一陣臭味，燻得在場所有人不是滋味。\n"NOR);
                        set("unwield_msg",HIR"$N將內力收回，"HIC"榴槤杖"HIR"立刻沉靜了下來，濃濃的臭味突然不見了。\n"NOR);
            }
        init_staff(20);
        setup();
}

int query_autoload()
{
   if (environment(this_object())->query("family/family_name")=="丐幫")
      return 1;
      return 0;
}

void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
  set_name (me->name(1)+"的"HIC"榴槤杖"NOR, ({ "durian staff","staff" }));
  else
  set_name (HIR"一把普通的木杖"NOR, ({ "staff" }));
}

