// made by ccat
// Et-sword.c by Casey
// super weapon 修改來自百變兵器及倚天劍 by bss
#include <ansi.h>
#include <weapon.h>
inherit EQUIP;
int weapon_type=0,sp;
object weapon,user;
void create()
{
     set_name(HBMAG+HIY"玄天九變"NOR,({"super weapon","weapon","super"}) );
     set_weight(15000);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long","上古時代所遺留下來的奇異兵器，可以變換成各種種類的兵器.\n"
                  +"( change <type>, ex: change sword )\n"
                  +"( type : unarmed sword blade whip dagger stabber )\n");
            set("unit", "件");
            set("value",2000);
            set("material","steal");
           }
        setup();
}
void init()
{
        add_action("do_change","change");
        add_action("do_wield","wield");
        add_action("do_unwield","unwield");
}
int do_change(string str)
{
        object me=this_player();
   switch(str)
   {
     case "unarmed":
           weapon_type=1;
           set("skill_type", "unarmed");
           set_name(HIY"如來大手印"NOR,({"rulai hand","hand"}));
           write(HBMAG+HIY"玄天九變"NOR"開始作奇異的變化.\n"HBMAG+HIY"玄天九變"NOR"化成了一雙"HIY"如來大手印"NOR"\n");
           set("weapon_prop/unarmed", 10);
//           init_unarmed(120);
           set("weapon_prop/damage",120);
           break;
     case "sword":
           weapon_type=2;
           set("skill_type", "sword");
           set_name(HIY"神龍劍"NOR,({"dragon sword","sword"}));
           write(HBMAG+HIY"玄天九變"NOR"開始作奇異的變化.\n"HBMAG+HIY"玄天九變"NOR"化成了一把"HIY"神龍劍"NOR".\n");
           set("weapon_prop/sword", 10);
//        init_sword(120);
           set("weapon_prop/damage",120);
           break;
     case "blade":
           weapon_type=3;
           set("skill_type", "blade");
           set_name(HIR"日月"HIY"神刀"NOR,({"sun_moon blade","blade"}));
           write(HBMAG+HIY"玄天九變"NOR"開始作奇異的變化.\n"HBMAG+HIY"玄天九變"NOR"化成了一把"HIR"日月"HIY"神刀"NOR"\n");
           set("weapon_prop/blade", 10);
//        init_sword(120);
           set("weapon_prop/damage",120);
           break;
     case "dagger":
           weapon_type=4;
           set("skill_type", "dagger");
           set_name(HIC"沉璧"NOR,({"moon dagger","dagger"}));
           write(HBMAG+HIY"玄天九變"NOR"開始作奇異的變化.\n"HBMAG+HIY"玄天九變"NOR"化成了一雙"HIC"沉璧"NOR".\n");
           set("weapon_prop/dagger",10);
//        init_dagger(120);
           set("weapon_prop/damage",120);
           break;
     case "whip":
           weapon_type=5;
           set("skill_type", "whip");
           set_name(HIM"紫玉晶鞭"NOR,({"gem whip","whip"}));
           write(HBMAG+HIY"玄天九變"NOR"開始作奇異的變化.\n"HBMAG+HIY"玄天九變"NOR"化成了一條"HIM"紫玉晶鞭"NOR".\n");
           set("weapon_prop/whip", 10);
//        init_whip(120);
           set("weapon_prop/damage",120);
           break;
     case "stabber":
     case "fan":
           weapon_type=6;
           set("skill_type", "stabber");
           set_name(HIR"陰陽寶扇"NOR,({"yengyang fan","fan"}) );
           write(HBMAG+HIY"玄天九變"NOR"開始作奇異的變化.\n"HBMAG+HIY"玄天九變"NOR"變成了一支"HIR"陰陽寶扇"NOR".\n");
           set("weapon_prop/stabber", 10);
//        init_stabber(120);
           set("weapon_prop/damage",120);
           break;
     default:
           write(HBMAG+HIY"玄天九變"NOR"左變右變,就是無法變成你要的東西.\n");
   }
    me->reset_action();
     return 1;
}
int do_wield(string str)
{
        user = this_player(); // 取得使用者
        weapon=this_object();
        sp=user->query_spi(1);
//        ::wield();      //因為已經設定了no_drop等....所以可以不用先做這項
        if(str=="all" ||
          (str=="rulai hand" && weapon_type==1) ||
          (str=="hand" && weapon_type==1) ||
          (str=="dragon sword" && weapon_type==2) ||
          (str=="sword" && weapon_type==2) ||
          (str=="sun_moon blade" && weapon_type==3) ||
          (str=="blade" && weapon_type==3) ||
          (str=="moon dagger" && weapon_type==4) ||
          (str=="dagger" && weapon_type==4) ||
          (str=="gem whip" && weapon_type==5) ||
          (str=="whip" && weapon_type==5) ||
          (str=="yengyang fan" && weapon_type==6) ||
          (str=="fan" && weapon_type==6))
        {
        switch(weapon_type)
        {
                case 1:
                        message_vision("$N將$n從懷中取出戴在手上，只見$N的身體隴罩在一片淡淡的黃光中，$N的力量增強了。\n"NOR,user,weapon);
                        break;
                case 2:
                        message_vision("$N大喝一聲:「神龍出鞘」，$n由龍嘴吐出，龍的鬥氣佈滿$N全身。\n",user,weapon);
                        break;
                case 3:
                        message_vision("$N運氣刀柄，剎那間$n的刀鞘發出耀眼金光，$N用力一拔，$n出鞘了!!!\n",user,weapon);
                        break;
                case 4:
                        message_vision(HIY"$N雙手忽然一抖，$n"HIY"就像變魔術般的出現在$N手上。\n"NOR,user,weapon);
                        break;
                case 5:
                        message_vision("$N用力抽出纏在腰間的$n，$n散發出令人不舒服的紫光。\n"NOR,user,weapon);
                        break;
                case 6:
                        message_vision("$N拿出藏在衣服裡的小$n放在掌上，用力一吹，一隻足有二尺長的$n出現在$N的手上。\n"NOR,user,weapon);
                        break;
                default:
                        message_vision("以$N現在的形態不能裝備，請先change再裝備。\n",weapon);
                        return 1;
                        break;
        }
        user->set_temp("wield_schange_weapon",1);
        set_heart_beat(1);
        }
        else
        {
        return notify_fail("你要裝備啥啊???\n");
        }
}
int do_unwield(string str)
{
        if( query("equipped") )
        {
        if(str=="all" ||
          (str=="rulai hand" && weapon_type==1) ||
          (str=="hand" && weapon_type==1) ||
          (str=="dragon sword" && weapon_type==2) ||
          (str=="sword" && weapon_type==2) ||
          (str=="sun_moon blade" && weapon_type==3) ||
          (str=="blade" && weapon_type==3) ||
          (str=="moon dagger" && weapon_type==4) ||
          (str=="dagger" && weapon_type==4) ||
          (str=="gem whip" && weapon_type==5) ||
          (str=="whip" && weapon_type==5) ||
          (str=="yengyang fan" && weapon_type==6) ||
          (str=="fan" && weapon_type==6))
        {
        switch(weapon_type)
        {
                case 1:
                        message_vision("$N把戴在手上的$n取下，珍而重之的收了起來。\n"NOR,user,weapon);
                        break;
                case 2:
                        message_vision("$N輕呼一聲:「神龍回鞘」，$n縮回了龍嘴。\n",user,weapon);
                        break;
                case 3:
                        message_vision("$N將手中$n往天上一拋，$n不偏不倚的落回鞘內。\n",user,weapon);
                        break;
                case 4:
                        message_vision(HIY"$N將手一抖，$n"HIY"便消失了。\n"NOR,user,weapon);
                        break;
                case 5:
                        message_vision("$N把$n重新纏回腰間。\n"NOR,user,weapon);
                        break;
                case 6:
                        message_vision("$N往大$n吹了一口氣，原本有二尺長的大扇子變成了只有二寸長的小扇子。\n"NOR,user,weapon);
                        break;
        }
        user->delete_temp("wield_schange_weapon");
        set_heart_beat(0);
        }
        else
        {
        return 0;
        }
        }
}
void heart_beat()
{
  object *enemy,who,ob;
  int i,j;

 if( !objectp(user) )
 {
    set_heart_beat(0);
    return;
 }

 if( user->is_fighting() && query("equipped") && user->query_temp("wield_schange_weapon") )
 {
    if( random(sp+100)> 100 )
    {
       enemy=user->query_enemy();
       i=random(sizeof(enemy));
       ob=enemy[i]->query_temp("weapon");
       if( !ob || random(10) > 6 )
       {
         message_vision(BLINK+HIY"$N突然感到由$n"BLINK+HIY"所傳來的一陣奇異的氣，身不由已的使出連續技!!!\n"NOR
         ,user,weapon);

         for(j=0;j<=2+random(3);j++)
           COMBAT_D->do_attack(user,enemy[i],user->query_temp("weapon"),2);
         return;
       }

 if( environment(user) == environment(enemy[i]) )
        if(!enemy[i]->query_temp("wield_schange_weapon"))
        if((userp(enemy[i]) && random(10) > 5) ||
          (!userp(enemy[i]) && random(10) > 8)  )
        {
          ob->unequip();
          message_vision(HIC"忽然一道神奇的藍光由"+weapon->query("name")+HIC"射出,擊中了$N的"+ob->query("name")+HIC"
只聽見ㄆㄧㄚ的一聲，"+ob->query("name")+HIC"竟然斷了!!!\n"
NOR,enemy[i]);
          if( !ob->query("bad"))
          {
            ob->set("name", "(斷毀)" + ob->query("name"));
             ob->set("bad",1);
          }

          ob->set("value",1);
          ob->set("weapon_prop/damage",0);
          ob->move(environment(enemy[i]));
          enemy[i]->rest_action();
          enemy[i]->delete_temp("wield_schange_weapon");
          }
         else
         {
          if(ob->query("bad1"))
          {
          ob->unequip();
          message_vision(HIM"忽然一道刺眼的紫光由"+weapon->query("name")+HIM"射向了$N的"+ob->query("name")+HIM"，
原本已經出現裂縫的"+ob->query("name")+HIM"竟然開始粉碎!!!，$N完全不感相信自己
的眼睛，過了不久，"+ob->query("name")+HIM"完全的消失在天地之間了!!!\n"NOR,enemy[i]);
          destruct(ob);
          message_vision(BLINK+HIY"\n$N眼看機會來了，奮不顧身的對$n"BLINK+HIY"發動猛烈的攻擊!!!\n"NOR,user,enemy[i]);
          call_out("quick_combat",2,enemy[i]);
          }
          if(ob)
          {
          ob->unequip();
          message_vision(HIG"忽然一道神奇的綠光由"+weapon->query("name")+HIG"射向了$N的"+ob->query("name")+HIG"，
$N見情況不對急忙將"+ob->query("name")+HIG"抽回，可惜慢了一步，"+ob->query("name")+HIG"
被綠光輕輕的碰到，只聽見「嘶」的一身，"+ob->query("name")+HIG"竟然出現了數道裂縫!!!\n"NOR,enemy[i]);
          }
          if( !ob->query("bad1"))
          {
            ob->set("name", "(折損)" + ob->query("name"));
            ob->set("bad1",1);
          }
          if( ob->query("weapon_prop/damage") > 10 )
          {
            ob->add("weapon_prop/damage",-10);
          }
          else
            ob->set("weapon_prop/damage",0);
          ob->wield();
        }
    }
  }

    return;
}
int quick_combat(object ob)
{
        int j;
         for(j=0;j<=2+random(3);j++)
           if(ob)
           COMBAT_D->do_attack(user,ob,user->query_temp("weapon"),2);
         return 1;
}
int query_autoload() { return 1; }
