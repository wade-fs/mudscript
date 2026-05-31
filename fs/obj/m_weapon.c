// /u/a/acelan/eqs/m_weapon.c 萬用武器 written by AceLan.............97.11.10
// Modify By AceLan 98.7.13 讓萬用更有看頭...ccc....

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
   object me= this_player();
   string c_unit, wield_part, weapon_type= me->query("weapon/e_type"); // new

   set_name( me->query("weapon/name"),({"special "+me->query("weapon/e_type"), me->query("weapon/e_type"), "m_weapon"}) );
   set_weight(1000);
   if( clonep() )
      set_default_object(__FILE__);
   // 下為新增部份...
   if( weapon_type == "whip")
   {
      c_unit= "柄";
      wield_part= "手中";
   }
   else if( weapon_type == "pen")
   {
      c_unit= "隻";
      wield_part= "手中";
   }
   else if( weapon_type == "ring")
   {
      c_unit= "只";
      wield_part= "指上";
   }
   else if( weapon_type == "armband")
   {
      c_unit= "個";
      wield_part= "臂上";
   }
   else                                      // 剩下的為 劍 刀 匕首 拂塵 扇
   {
      c_unit= "把";
      wield_part= "手中";
      if( weapon_type == "bow") {
      set("can_hold",1);
      // 初始化....把裝備的箭設成id = none ,amount = 0
      set("arrow/id","none");
      set("arrow/amount",0);
      set("arrow/name","空的");

      }
   }

   set("long","這"+c_unit+me->query("weapon/c_type")+"是以"+ me->query("weapon/source1")+"配合"+ me->query("weapon/source2")+"所鑄成的, 它正閃爍著異光。");
   set("unit", "把");
   set("value",0);                           // 無價之寶...ccc....
   set("material","steal");
   set("sharp",8);

   // 加強了裝備武器及卸下武器的訊息...
   // 指 扇 筆 指環 臂環
   if( me->query("weapon/type") == "stabber" || me->query("weapon/type") == "unarmed")
   {
      set("wield_msg", HIW"只見$N大喝一聲, 一道白光迅速由$N懷中竄出, \n在空中盤桓三圈後停在$N的"+wield_part+"化成一"+c_unit+"獨特的"+ me->query("weapon/name")+"。\n"NOR);
      set("unwield_msg", HIW"突然間$N的胸腹之間吸足了氣, 朝"+wield_part+"的$n輕輕一吹, \n只見$n慢慢的化作一縷\輕煙, 隱沒在$N的胸腹之間。\n"NOR);
   }
   else // if( c_unit == "把" || c_unit == "柄")// 指 劍 刀 匕首 拂塵...扇子不會出現
   {
      set("wield_msg", HIW"$N輕輕的將"+ me->query("weapon/name")+HIW"由背後抽出, 只見一道耀眼而詭異的光芒注入了$N身上。\n"NOR);
      set("unwield_msg", HIW"$N將手中的$n"HIW"隨手往天上一丟, 只見它巧妙的落回了背後。\n"NOR);
   }

   set("no_drop", 1);
   set("no_give", 1);
   set("no_get", 1);
   set("no_auc", 1);

   init_sword( me->query("weapon/value"));
   set("weapon_prop/damage", me->query("weapon/value"));
   set("skill_type", me->query("weapon/type"));
   setup();
}

// 新增加 Modify by AceLan....99.3.7
// 看能不能修復攻擊力互相衝突
void init()
{
   if( environment() == this_player() )
   {
   init_sword(this_player()->query("weapon/value"));
      set("weapon_prop/damage", this_player()->query("weapon/value"));
   }
}

int query_autoload()
{
   return 1;
}

