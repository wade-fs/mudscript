//增加seteuid(getuid())的判別 調整check_item訊息 與增加check_item之後能增加醫術(cure)的經驗值 by blazakira 2011/11/1

inherit COMBINED_ITEM;

void create()
{
  seteuid(getuid());
  set_name("仙山靈芝", ({"super item","item"}) );
  set("long",
    "此物乃蜀中將軍自蜀山神峰採來之神藥，專克血氣失調。\n"+
    "此要須經藥師調配(check_item super item)，方得食用(eat pill)。\n");
  set("unit", "棵");
  set("base_unit", "棵");
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
  if( (arg=="item" || arg=="super item") )
  {
    object user,ob;
    user = this_player();

    if( user->query_skill_mapped("cure")=="godcure" )
    {
      cure = user->query_skill("cure",1)*5/3;
    } else {
      cure = user->query_skill("cure",1);
    }
//    cure = user->query_skill("cure",1); //這是原本的那句

    if( cure > 14)
    {
      str=user->query_skill_mapped("force");
      if( !str )
        return notify_fail("你並沒有催動內力的方法(enable)，導致無法繼續煉製下去!!\n");
      ob=new("/open/gsword/obj/f_pill");
      message_vision("$N用"+to_chinese(str)+"催動內力於掌心處，試著將"+query("name")+"煉製成"+ob->query("name")+"。\n", user);
//      message_vision("$N試著將靈芝製成仙丹。\n", user);
      if( user->query("force") < (int)cure*2 )
        return notify_fail("你的內力不足，導致無法繼續煉製下去!!\n");
      user->add("force",-(int)cure*2);
      cure = cure/3 -1;
      ob->move(this_player());
      ob->add_amount((int)cure);
      if( user->query_skill("cure",1) < 120 )
        user->improve_skill("cure",(int)random((int)cure)/2);
      else
        user->improve_skill("cure",(int)random((int)cure)/10+1);
      add_amount(-1);
    } else
      message_vision("$N的醫術太低，無法將靈芝製成仙丹。\n",user);
    return 1;
  }
  return 0;
}
