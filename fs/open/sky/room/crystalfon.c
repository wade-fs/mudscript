inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIB"晶之封印石"NOR,({"crystal fon stone","stone"}));
        set("long","一個封印著神兵利器的神秘石頭，上面有著數個大大小小不等的\n"
                  +"奇形怪洞，應該可以放入解開封印的物品，若想要得到封印的神\n"
                  +"兵，可以將你所得到的解封印的物品(insert)進去，就可以讓神\n"
                  +"兵神器重新現世。\n");
        set("unit","尊");
        set("value",100);
        set("no_get",1);
        set("no_sac",1);
        set("no_auc",1);
        set_weight(500000);
        setup();
}

void init()
{
        add_action("do_insert","insert");
}

int do_insert(string str)
{
        object ob=this_object(),me=this_player();

        if( !str )
        return 0;

        switch(str)
        {
        case "com-shells":

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        if(!ob->query("com")==1 && (present(str,me)->query("specialitem")==1) )
        {
        message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
        ob->set("com",1);
        destruct(present(str,me));
        call_out("check",1,ob);
        }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
        }
        break;

        case "free-shells":

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        if(!ob->query("free")==1 && (present(str,me)->query("specialitem")==1) )
        {
        message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
        ob->set("free",1);
        destruct(present(str,me));
        call_out("check",1,ob);
        }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
        }
        break;

        case "growth-shells":

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        if(!ob->query("growth")==1 && (present(str,me)->query("specialitem")==1) )
        {
        message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
        ob->set("growth",1);
        destruct(present(str,me));
        call_out("check",1,ob);
        }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
        }
        break;

        case "rigid-shells":

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        if(!ob->query("rigid")==1 && (present(str,me)->query("specialitem")==1) )
        {
        message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
        ob->set("rigid",1);
        destruct(present(str,me));
        call_out("check",1,ob);
        }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
        }
        break;

        case "stable-shells":

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        if(!ob->query("stable")==1 && (present(str,me)->query("specialitem")==1) )
        {
        message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
        ob->set("stable",1);
        destruct(present(str,me));
        call_out("check",1,ob);
        }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
        }
        break;

        case "will-shells":

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        if(!ob->query("will")==1 && (present(str,me)->query("specialitem")==1) )
        {
        message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
        ob->set("will",1);
        destruct(present(str,me));
        call_out("check",1,ob);
        }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
        }
        break;

        case "wish-shells":

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        if(!ob->query("wish")==1 && (present(str,me)->query("specialitem")==1) )
        {
        message_vision(HIC"$N將"NOR"$n"HIC"鑲入了封印之石，只見封印之石緩緩列開一道縫隙並透出陣陣藍光!!\n"NOR,me,present(str,me));
        ob->set("wish",1);
        destruct(present(str,me));
        call_out("check",3,ob);
        }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
        }
        break;

        default:

        if( !present(str,me) )  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

        message_vision("$N似乎想放什麼東西，但卻找不到正確的位置放!!\n",me);
        break;
        }
        return 1;

}

int check(object ob)
{
        ob->add("check",1);

        if(ob->query("check") == 7 )
        {
        tell_object(users(),HIC"\n\n\t大地忽然劇烈地憾動了起來，在極遠處的一座山頂上落下了數道的閃電!!\n"NOR);
        tell_object(users(),HIC"\n\t遠處的閃電七彩繽紛，輕輕地劃過了天際，劃亮了整個天空!!\n"NOR);
        tell_object(users(),HIC"\n\t雷聲憾動了天地，飛鳥走獸們都慌忙的飛奔走散!!\n"NOR);
        call_out("msg1",5,ob);
        }
        return 1;
}

int msg1(object ob)
{
        object me=this_player();
        tell_object(users(),HIC"\n\n\t在天靈地界中的"HIB"晶之封印石"HIC"因為"HIG+ me->query("name")+HIC"的努力而解開了!!\n"NOR);
        tell_object(users(),HIC"\n\t因為失去了神力護持的"HIB"晶之封印石"HIC"開始劇烈抖動而開始崩散消逝!!\n"NOR);
        call_out("msg2",5,ob);
        return 1;
}

int msg2(object ob)
{
        object me=this_player(),room=environment(me);
        tell_object(users(),HIC"\n\n\t在天靈地界塵封已久的"HIM"「"HIR"紅"HIY"黃"HIC"晶魂"HIM"」"NOR+HIC"從"HIB"晶之封印石"HIC"中得到了解放而現世了!!\n"NOR,ob);
        message_vision(HIW"\n\t七顆解開封印的貝殼轉化為七束光茫，緩緩注入了"HIM"「"HIR"紅"HIY"黃"HIC"晶魂"HIM"」"NOR+HIW"之中轉化為不可思議的力量!!\n",ob);
        message_vision(HIW"\n\t光茫消散之後"HIM"「"HIR"紅"HIY"黃"HIC"晶魂"HIM"」"NOR+HIW"緩緩凝聚在$N手中!!\n"NOR,me);
        new("/autoload/sky/red_yellow")->move(me);
        write_file("/log/sky/crystalfon",sprintf("%s(%s) 解開了「紅黃晶魂」於 %s\n",me->name(1),me->query("id"),ctime(time())));
        room->set("no_reset",1);
        destruct(ob);
        return 1;
}
