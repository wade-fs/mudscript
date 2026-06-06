// change by adam
//增加seteuid(getuid())的判別 調整check_item訊息 與增加check_item之後能增加醫術(cure)的經驗值 by blazakira 2011/11/1

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
  seteuid(getuid());
  set_name(HIC"千年天山雪蓮"NOR, ({"force item","item"}) );
  set("long",
    "此物乃是吸收千年天地精華精華的神藥之神藥，可以瞬間恢復內力。\n"+
    "此要須經藥師調配(check_item force item)，方得食用(eat pill)。\n");
  set("unit", "棵");
  set("base_unit", "棵");
  set("no_sell",1);
  set("value",2500);
  set("base_weight", 50);
  set_amount(1);
  setup();
}

void init()
{
  if( this_player()==environment() )
  {
    add_action("check_item","check_item");
  }
}

int check_item(string arg)
{
  int cure;
  string str;
  if( (arg=="item" || arg=="force item") && (query("unit") == "棵") )
  {
    object user,ob;
    user = this_player();
    if( user->query_skill_mapped("cure")=="godcure" )
    {
      cure = user->query_skill("cure"); //估計值為160
    } else {
      cure = user->query_skill("cure")/2; //估計值為80
    }
    if( cure > 14)
    {
      str=user->query_skill_mapped("force");
      if( !str )
        return notify_fail("你並沒有催動內力的方法(enable)，導致無法繼續煉製下去!!\n");
      ob=new("/open/gsword/obj/ff_pill");
      message_vision("$N用"+to_chinese(str)+"催動內力於掌心處，試著將"+query("name")+"煉製成"+ob->query("name")+"。\n", user);
//      message_vision("$N試著將$n製成靈丹。\n",user,this_object());
      if( user->query("force") < (int)cure*2 )
        return notify_fail("你的內力不足，導致無法繼續煉製下去!!\n");
      user->add("force",-(int)cure*2);
      cure = cure/2;
      ob->move(this_player());
      ob->add_amount((int)cure);
      if( user->query_skill("cure",1) < 120 )
        user->improve_skill("cure",random((int)cure/2)); //估計值為0~40
      else
        user->improve_skill("cure",(int)random((int)cure/4)+1); //估計值為1~11
      add_amount(-1);
    } else
      message_vision("$N的醫術太低，無法將$n製成靈丹。\n",user,this_object());
    return 1;
  }
  return 0;
}
