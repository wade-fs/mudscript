//edit by neverend
//將receive_wound與receive_damage的攻擊參數補上攻擊方之參數 by blazakira 2011/7/20

#include <armor.h>
#include <ansi.h>
inherit EQUIP;
inherit SSERVER;

void create()
{
  set_name(HBBLU+HIC"水瑟天光"NOR, ({ "water-light-cloak" ,"cloak" }) );
  set_weight(50);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","曾經是天靈地界中，一位絕代戰神所著的披肩，承襲著他絕強的精神意念，隨時\n"
                          +"為著他的下一位繼承者散發出強絕的攻擊能力。\n");
    set("unit", "件");
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_sec",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_steal",1);
    set("no_save",1);
    set("no_get",1);
    set("value", 300000);
    set("material", "steel");
    set("armor_type", "cape");
    set("armor_prop/armor", 50);
    set("armor_prop/dodge", 5);
    set("armor_prop/parry", 5);
    set("armor_prop/unarmed", 5);
    set("armor_prop/force", 10);
    set("wear_msg","$n"HIW"在蕭瑟的秋水下，讓天際泛起了陣陣炫目的光彩，耀眼奪目。\n"NOR);
    set("unequip_msg",HIW"耀眼炫目的光彩不再，$n"+HIW"漸漸穩沒在蕭瑟的秋水下。\n"NOR);
  }
  setup();
}

void init()
{
  object ob,user;
  ob = this_object();
  user=environment(ob);
  if( !ob || !user ) return;
  if( !ob->query("boss") ) ob->set("boss",user->query("id"));
}

int wear()
{
  object me;
  int result = ::wear();
  if( query("equipped"))
  {
    me=environment();
//    message_vision("$n"HIW"在蕭瑟的秋水下，讓天際泛起了陣陣炫目的光彩，耀眼奪目。\n"NOR,me,this_object());
    set_heart_beat(1);
  }
  return result;
}

int unequip()
{
  object me=environment();
  int result = ::unequip();
  if( !query("equipped") )
  {
//    message_vision(HIW"耀眼炫目的光彩不再，$n"+HIW"漸漸穩沒在蕭瑟的秋水下。\n"NOR,me,this_object());
    set_heart_beat(0);
  }
  return result;
}

void heart_beat()
{
  object *enemy,user=environment();
  int i,j,k,md,ud;
  if(!this_object() || !user) return ;
  if ( !objectp(user) )
  {
    set_heart_beat(0);
    return;
  }

  i=user->query("combat_exp")/1000000;
  if( i > 10) i=10;
  if( i <  1)  i=1;

  k=random(i);
  if(user->query("id")=="neverend" || user->query_temp("blaz/kon")==1) k=9;

  ud=user->query_skill("dodge");

  if( user->is_fighting() && query("equipped") )
  {
    if( (random(ud)+1) > random(150)+50 )
    {
      enemy=user->query_enemy();
      j=random(sizeof(enemy));

      if( environment(user) == environment(enemy[j]) )
      {

        message_vision(sprintf(HIW"突然由"HBBLU+HIC"水瑟天光"NOR+HIW"中傳出一陣驚天狂嘯，$N猶如絕代戰神附身，將戰意發揮到極限使出戰神絕技\n"NOR),user,enemy[j]);
        message_vision(sprintf(HIM"－＝≡ "HBBLU+HIC"驚 － 天 － 動 － 地 － 式"NOR+HIY" ～◎～ "HBBLU+HIC"狂 － 滅 － 天 － 九 － 絕"NOR+HIM" ≡＝－\n\n"NOR),user,enemy[j]);

        switch(k)
        {
          case 0:
            message_vision(HIR"狂滅天九絕第一式"HBRED+HIY"【 天翔奔雷破 】"NOR+HIR"由天降下的無數雷球電氣四射，向$n狂襲。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("gin",220,user);
            enemy[j]->receive_damage("sen",220,user);
            enemy[j]->receive_damage("kee",400,user);
            COMBAT_D->report_status(enemy[j]);
            break;

          case 1:
            message_vision(HIC"狂滅天九絕第二式"HBCYN+HIC"【 天風捲千鈞 】"NOR+HIC"龐然巨大的龍捲颶風狂吹亂掃，向$n襲擊。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("gin",240,user);
            enemy[j]->receive_damage("sen",240,user);
            enemy[j]->receive_damage("kee",600,user);
            COMBAT_D->report_status(enemy[j]);
            break;

          case 2:
            message_vision(HIW"狂滅天九絕第三式"HBWHT+HIW"【 天龍舞飛旋 】"NOR+HIW"無數的龍氣聚然成形激射狂旋，向$n飛舞。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("gin",260,user);
            enemy[j]->receive_damage("sen",260,user);
            enemy[j]->receive_damage("kee",800,user);
            COMBAT_D->report_status(enemy[j]);
            break;

          case 3:
            message_vision(HIB"狂滅天九絕第四式"HBWHT+HIB"【 天水月流轉 】"NOR+HIB"朦朧的月色若隱若現輕盈流轉，向$n盈繞。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("gin",280,user);
            enemy[j]->receive_damage("sen",280,user);
            enemy[j]->receive_damage("kee",1000,user);
            COMBAT_D->report_status(enemy[j]);
            break;

          case 4:
            message_vision(HIY"狂滅天九絕第五式"HBYEL+HIY"【 天將伏千軍 】"NOR+HIY"威武的神將慕然出現身旋四轉，向$n急攻。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("gin",300,user);
            enemy[j]->receive_damage("sen",300,user);
            enemy[j]->receive_damage("kee",1200,user);
            COMBAT_D->report_status(enemy[j]);
            break;

          case 5:
            message_vision(HIG"狂滅天九絕第六式"HBGRN+HIG"【 天風馳陰雷 】"NOR+HIG"低鳴陰沉的天際突然風雷驟現，向$n猛降。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("gin",320,user);
            enemy[j]->receive_damage("sen",320,user);
            enemy[j]->receive_damage("kee",1400,user);
            COMBAT_D->report_status(enemy[j]);
            break;

          case 6:
            message_vision(HIM"狂滅天九絕第七式"HBMAG+HIM"【 天靈箭幻舞 】"NOR+HIM"大地的靈氣如幻箭般激射四起，向$n狂射。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("gin",340,user);
            enemy[j]->receive_damage("sen",340,user);
            enemy[j]->receive_damage("kee",1600,user);
            COMBAT_D->report_status(enemy[j]);
            break;

          case 7:
            message_vision(HIR"狂滅天九絕第八式"HBRED+HIR"【 天火怒燎原 】"NOR+HIR"天神怒火由四面八方襲捲而至，向$n焚燒。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("gin",360,user);
            enemy[j]->receive_damage("sen",360,user);
            enemy[j]->receive_damage("kee",1800,user);
            COMBAT_D->report_status(enemy[j]);
            break;

          case 8:
            message_vision(HIC"狂滅天九絕第九式"HBBLU+HIC"【 天冰寒星雨 】"NOR+HIC"萬點的寒星如驟雨般破空急降，向$n暴降。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("gin",380,user);
            enemy[j]->receive_damage("sen",380,user);
            enemy[j]->receive_damage("kee",2000,user);
            COMBAT_D->report_status(enemy[j]);
            break;

          case 9:
            message_vision(HIR"狂滅天九絕第一式"HBRED+HIY"【 天翔奔雷破 】"NOR+HIR"由天降下的無數雷球電氣四射，向$n狂襲。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("kee",100,user);
            COMBAT_D->report_status(enemy[j]);
            message_vision(HIC"狂滅天九絕第二式"HBCYN+HIC"【 天風捲千鈞 】"NOR+HIC"龐然巨大的龍捲颶風狂吹亂掃，向$n襲擊。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("kee",100,user);
            COMBAT_D->report_status(enemy[j]);
            message_vision(HIW"狂滅天九絕第三式"HBWHT+HIW"【 天龍舞飛旋 】"NOR+HIW"無數的龍氣聚然成形激射狂旋，向$n飛舞。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("kee",100,user);
            COMBAT_D->report_status(enemy[j]);
            message_vision(HIB"狂滅天九絕第四式"HBWHT+HIB"【 天水月流轉 】"NOR+HIB"朦朧的月色若隱若現輕盈流轉，向$n盈繞。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("kee",100,user);
            COMBAT_D->report_status(enemy[j]);
            message_vision(HIY"狂滅天九絕第五式"HBYEL+HIY"【 天將伏千軍 】"NOR+HIY"威武的神將慕然出現身旋四轉，向$n急攻。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("kee",100,user);
            COMBAT_D->report_status(enemy[j]);
            message_vision(HIG"狂滅天九絕第六式"HBGRN+HIG"【 天風馳陰雷 】"NOR+HIG"低鳴陰沉的天際突然風雷驟現，向$n猛降。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("kee",100,user);
            COMBAT_D->report_status(enemy[j]);
            message_vision(HIM"狂滅天九絕第七式"HBMAG+HIM"【 天靈箭幻舞 】"NOR+HIM"大地的靈氣如幻箭般激射四起，向$n狂射。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("kee",100,user);
            COMBAT_D->report_status(enemy[j]);
            message_vision(HIR"狂滅天九絕第八式"HBRED+HIR"【 天火怒燎原 】"NOR+HIR"天神怒火由四面八方襲捲而至，向$n焚燒。\n"NOR,user,enemy[j]);
            enemy[j]->receive_damage("kee",100,user);
            COMBAT_D->report_status(enemy[j]);
            message_vision(HIC"狂滅天九絕第九式"HBBLU+HIC"【 天冰寒星雨 】"NOR+HIC"萬點的寒星如驟雨般破空急降，向$n暴降。\n"NOR,user,enemy[j]);
            enemy[j]->receive_wound("gin",400,user);
            enemy[j]->receive_wound("sen",400,user);
            enemy[j]->receive_wound("kee",2000,user);
            enemy[j]->start_busy(1);
            COMBAT_D->report_status(enemy[j]);
            break;
        }
      }
    }
  }
  return ;
}

int query_autoload()
{
  return 1;
}

