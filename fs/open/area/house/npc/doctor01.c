 inherit NPC;
#include <ansi.h>
string do_ask01();

void create()
{
        set_name("劉良",({"liu liang","liang"}));
        set("gender","男性");
        set("title",YEL + "行腳大夫" + NOR);
        set("long",@LONG
自幼隨父親行醫，走遍大江南北，見識過不少奇奇怪怪的怪病；醫術
是其父所教導，其醫治之方法，十分奇特，雖然能對症下藥，不過卻
很難令一般世人所接受，可以肯定的是，他對於一些奇特的怪病會十
分的感興趣。
LONG);
        set("inquiry",([
"怪病": (: do_ask01 :),
]));
        set("age",45);
        set("con",10);
        set("str",1);
        set("combat_exp",200);
        setup();
}

int accept_object(object me,object obj)
{
object ob = this_object();
                if( ob->query_temp("start-cure") && obj->query("id") == "snake gall")
                {
                        message_vision("\n$N說：這一帖藥沒錯，接下來下一帖，就是親人的心臟．．\n",ob);
                        message_vision(HIY + "\n\n在場的所有人聽到$N說出的這帖藥劑，全都驚訝不已！！\n\n\n" + NOR,ob);
                        call_out("do_answer",3,me);
                        ob->delete_temp("start-cure");
                }
return 1;
}

int do_answer(object me)
{
        object ob;

        ob = present("chou",environment(me));

        message_vision("
$N思考了一下～

"+HIR+"只見$N眼睛充滿堅毅的神情，轉身拿起掛在牆上的那把砍刀，手一揮
，鮮血狂噴～左胸至右腰際畫下了一道深且長的傷痕～"+NOR+"

嚇傻了在場所有人！\n",ob);
        call_out("do_answer2",2,me);
return 1;
}

int do_answer2(object me)
{
        object ob = present("chou",environment(me));

        message_vision("
$N緩緩說到：大夫．．麻煩你了．．
\n",ob);
        ob->die();
        call_out("do_answer3",2,me);
return 1;
}

int do_answer3(object me)
{
        object ob,obj;

        ob = this_object();
        obj = present("baby",environment(ob));

        message_vision(HIW + "
$N趕忙的將屍體給解剖～取出緩緩跳動的鮮紅心臟．．．

一氣喝成的將蛇膽跟心臟磨碎混合～
" + NOR,ob);

        if ( obj )
        {
                message_vision(HIW + "

最後將黯紅色的[混合藥劑]給塗抹在小嬰兒身上．．．
\n" + NOR,ob);
        destruct(obj);
        obj = new("/open/area/house/npc/children01");
        obj->set_temp("cure_id",me->query("id"));
        obj->set_temp("cure",1);
        obj->move(environment(ob));
        }
        else
        {
                message_vision(HIR + "
$N瞪大眼睛看尋找著著嬰兒，手中拿著黯紅的[混合藥劑]漸漸變黑．．．

$N搖頭嘆息：唉唉～這藥劑不能接觸空氣太久．．．已經失效了，老夫也無能為力。
" + NOR,ob);
        }
                message_vision("
$N說：老夫的工作到此告一段落了，接下來就看這孩子的命了，老夫先行告辭～

$N轉頭走出了木屋，留下了錯愕$n．．．
" + NOR,ob,me);

        destruct(ob);
return 1;
}

string do_ask01()
{
        object ob,me;

        ob = this_object();
        me = this_player();

        message_vision("劉良睜大眼說：有奇特的怪病嗎？好～老夫馬上跟你走，不過．．．
老夫沒什麼耐心～如果走太久了還沒到，請原諒老夫不告而別。\n\n",ob);

        ob->do_command("follow "+me->query("id"));
        ob->set_temp("start-walk",1);
        return "走吧～老夫準備好了！\n";
}

void heart_beat()
{
        object ob,me,room,target;
        int i,j;

        ob = this_object();
        me = this_player();
        room = environment(ob); 

        if(ob->query_temp("start-walk"))
        {
                if(ob->query_temp("start-walk") <= 25)
                {
                        if(room->query_temp("area/house",1) && present("baby",room) )
                        {
                                ob->delete_temp("start-walk");
                                ob->set_temp("start-cure",1);
                                target = present("baby",room);
                                message_vision("$N神色緊張的看著嬰兒！\n\n",ob);
                                message_vision("$N神情凝重的說：這孺子被下蠱毒．．．\n",ob);
                                message_vision("$N說：老夫目前有方法醫治他，不過尚缺兩種藥帖，其中一樣是蛇膽，不過
必須是成年大蛇的蛇膽才有用～\n",ob);
                                message_vision("$N說：而另一個藥帖，等老夫拿到了蛇膽再說．．\n",ob);
                                ob->do_command("follow none");
                        }
                        else
                        {
                                ob->add_temp("start-walk",1);
                                i = ob->query_temp("start-walk");
        
                                i %= 5 ;

                                switch(i)
                                {
                                        case 0 :
                                                message_vision("$N說著：老夫等不及了～快點！\n",ob);
                                                break;

                                        case 1 :
                                                message_vision("$N說著：加緊腳步～快點！\n",ob);
                                                break;
                                        case 2 :
                                                message_vision("$N說著：還沒到嗎？\n",ob);
                                                break;
                                        case 3 :
                                                message_vision("$N說著：老夫快奈不住性子了．．．\n",ob);
                                                break;
                                        case 4 :
                                                message_vision("$N說著：抱歉，再沒到達，原諒老夫不告而別．．．\n",ob);
                                                break;
                                        default:
                                                message_vision("．．．．$N臉上表現出不悅的臉色\n",ob);
                                                break;
                                }
                        }
                }
                else
                {
                        message_vision("$N一轉頭，人漸漸消失在你的眼前。\n",ob);
                        destruct(ob);
                }
        }       
        ::heart_beat(1);
}
