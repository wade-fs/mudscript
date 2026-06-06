// 為保障doctor權利..只允許給doctor..check
// 道士可以煉丹.所以..將super item及force item開放給taoist
inherit COMBINED_ITEM;
void create()
{
        set_name("仙山靈芝", ({"super item","item"}) );
        set("long",
"此物乃蜀中將軍自蜀山神峰採來之神藥,專克血氣失調.\n"+
"此要須經藥師調配(check item),方得食用(eat pill)。\n");
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
                add_action("check_item","check");
        }
}

int check_item(string arg)
{
     int cure;
     if( (arg=="item" || arg=="super item") )
     {
        object user,ob;
        user = this_player();
       if(user->query("class")!="doctor"&&user->query("class")!="taoist")
        return notify_fail("你職業不是醫者或道士無法藥株製成藥丸!!\n");
        cure = user->query_skill("cure");
        cure = cure /4;
      if( cure > 14)
        {
          if(user->query("class")=="taoist")
           cure=cure/2;
          message_vision("$N試著將靈芝製成仙丹.\n", user);
          ob=new("/open/doctor/pill/f_pill");
          ob->move(this_player());
          ob->add_amount((int)cure);
          add_amount(-1);
        }else
          message_vision("$N的醫術太低,無法將靈芝製成仙丹.\n", user);
        return 1;
     }
     return 0;
}

