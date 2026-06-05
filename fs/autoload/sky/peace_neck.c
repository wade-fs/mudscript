//改變使用者的判定為me = environment(this_object()) 與 wear形式為int wear() (參考殺意魔戒) by blazakira 2011/7/20

#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
  set_name(HBBLU+HIC + "寧心淨靈" + NOR, ({ "peace-heart-neck", "neck" }) );    
  set_weight(50);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "天靈地界中，擁有神聖淨化力量的一條項鍊。\n");
    set("unit", "條");
    set("value", 300000);
    set("material", "steal");
    set("attribute","saint");
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_sec",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_steal",1);
    set("no_save",1);
    set("no_get",1);
    set("armor_prop/armor", 5);
    set("armor_prop/dodge", 5);
    set("armor_prop/parry", 5);
    set("armor_prop/unarmed", 5);
    set("armor_prop/force", 5);
    set("wear_msg",HIW + "戴上$n" + HIW + "的$N" + HIW + "，心靈如同被洗滌了一般，感受到思緒無限的寧靜。\n" + NOR);
    set("unequip_msg",HIW + "卸下$n" + HIW + "的$N" + HIW + "，心情慢慢回復往常一般，而心緒卻突然感受到了一陣的紊亂。\n" + NOR);
  }
  setup();
//  set_heart_beat(1);
}

void init()
{
  object me,ob;
  ob = this_object();
  me = environment();
  if( !ob || !me ) return;
  if( !ob->query("boss") ) ob->set("boss",me->query("id"));
}

int wear()
{
  object me;
  int result = ::wear();
  if( query("equipped"))
  {
    me=environment();
//    message_vision(HIW + "戴上$n" + HIW + "的$N，心靈如同被洗滌了一般，感受到思緒無限的寧靜。\n" + NOR,me,this_object());
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
//    message_vision(HIW + "卸下$n" + HIW + "的$N，心情慢慢回復往常一般，而心緒卻突然感受到了一陣的紊亂。\n" + NOR,me,this_object());
    set_heart_beat(0);
  }
  return result;
}

void heart_beat()
{
  object *enemy,ob = this_object(),me=environment();

  int i,j;

  if( !ob || !me || !objectp(me) )
  {
    set_heart_beat(0);
    return;
  }

  if( query("equipped") )
  {
    if(random(100) > 15)
    {
      me->receive_curing("kee",15);
      me->receive_heal("kee",15);
      me->receive_curing("gin",10);
      me->receive_heal("gin",10);
      me->receive_curing("sen",10);
      me->receive_heal("sen",10);
    }
    if( me->is_fighting() )
    {
      enemy=me->query_enemy();
      if(!sizeof(enemy)) return ;
      i=random(sizeof(enemy));
      j=enemy[i]->query("bellicosity");
      if( environment(me) == environment(enemy[i]) )
      {
        if( j <= 0 ) return ;
        if( me->query("attribute") == "saint" )
        {
          if( random(10) == 5 )
          {
            message_vision(HIY + "$N" + HIY + "的"+ob->query("name")+HIY + "散發出強大的淨化能量，淨化了$n" + HIY + "的殺氣。\n" + NOR,me,enemy[i]);
            j=j-500;
            if( j < 0 ) j=0;
            enemy[i]->set("bellicosity",j);
          } else {
            j=j-10;
            if( j <= 0 ) j=0;
            enemy[i]->set("bellicosity",j);
          }
        }
        else if( me->query("attribute") == "dark" )
        {
          if( random(10) == 5 )
          {
            message_vision(HIY + "$N" + HIY + "的"+ob->query("name")+HIY + "發出一股清聖的力量，淨化了$n" + HIY + "的殺氣。\n" + NOR,me,enemy[i]);
            j=j-150;
            if( j < 0 ) j=0;
            enemy[i]->set("bellicosity",j);
          } else {
            j=j-2;
            if( j <= 0 ) j=0;
            enemy[i]->set("bellicosity",j);
          }
        } else {
          if( random(10) == 5 )
          {
            message_vision(YEL + "$N" + NOR+YEL + "的"+ob->query("name")+NOR+YEL + "發出一絲清聖的力量，淨化了$n" + NOR+YEL + "的殺氣。\n" + NOR,me,enemy[i]);
            j=j-250;
            if( j < 0 ) j=0;
            enemy[i]->set("bellicosity",j);
          } else {
            if( j < 0 ) j=0;
            enemy[i]->set("bellicosity",j);
          }
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
