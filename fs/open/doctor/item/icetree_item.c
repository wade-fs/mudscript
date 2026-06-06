// 為保障doctor權利..只允許給doctor..check
// 天山續斷膏
//排版 調整check_item訊息 與增加check_item之後能增加醫術(cure)的經驗值 by blazakira 2011/11/1

inherit COMBINED_ITEM;

void create()
{
  seteuid(getuid());
  set_name("天山寒霜草",({"ice_tree item","item"}));
  set("long",
    "此乃銀針門掌門華陀先生費經千辛萬苦從天山所移植過來的藥草。此草對外傷有著起死回生\n"+
    "的功效，但是需要煉製(make)方能使用。\n");
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
    add_action("make_item","make");
}

int make_item(string arg)
{
  int cure;
  string str;
  if( (arg=="item" || arg=="ice_tree item") && (query("unit") == "棵") )
  {
    object user,ob;
    user = this_player();
    if(user->query("class")!="doctor")
      return notify_fail("你職業不是醫者無法將藥株製成藥丸!!\n");
    cure = user->query_skill("cure"); //估計值為160
    cure = cure /4; //估計值為40
    if( cure > 10)
    {
      str=user->query_skill_mapped("force");
      if( !str )
        return notify_fail("你並沒有催動內力的方法(enable)，導致無法繼續煉製下去!!\n");
      ob=new("/open/common/obj/plaster2");
      message_vision("$N用"+to_chinese(str)+"催動內力於掌心處，試著將"+query("name")+"煉製成"+ob->query("name")+"。\n", user);
//      message_vision("$N試著將天山寒霜草製成天香斷續膏。\n", user);
      if( user->query("force") < (int)cure*2 )
        return notify_fail("你的內力不足，導致無法繼續煉製下去!!\n");
      user->add("force",-(int)cure*2);
      ob->move(this_player());
      ob->add_amount((int)cure);
      if( user->query_skill("cure",1) < 120 )
        user->improve_skill("cure",random((int)cure)); //估計值為0~40
      else
        user->improve_skill("cure",random((int)cure/4)+1); //估計值為1~11
      add_amount(-1);
    } else
      message_vision("$N的醫術太低，無法將寒霜草製成斷續膏。\n", user);
    return 1;
  }
  return 0;
}
