//更改玩家密碼的指令by bss
inherit F_CLEAN_UP;

private void check1(string str,object me,object ob);

void create()
{
        seteuid(getuid());
}
int main(object me, string arg)
{
        string name;
        object ob;

        if( !arg || arg=="" )
                return notify_fail("指令格式﹕chpw 玩家id \n");

        name=arg;
        ob = new(LOGIN_OB);
        ob->set("id",arg);
        if(!ob->restore())
        {
                write("沒有這個使用者!!!\n");
                destruct(ob);
                return 1;
        }
//        if(wizhood(ob)=="(admin)"||wizhood(ob)=="(manager)")
//        {
//                printf("%s\n",SECURITY_D->get_status(name));
//                printf("你沒有更改%s(%s)密碼的權力!!!\n",ob->query("name"),ob->query("id"));
//                return 1;
//        }
        printf("你確定要更改%s(%s)的密碼嗎??(y/n)\n",ob->query("name"),ob->query("id"));
        input_to("check1",0, me,ob);
        return 1;
}
private void check1(string str,object me,object ob)
{
        string pass;

        if( str=="" ) {
        printf("你確定要更改%s(%s)的密碼嗎??(y/n)\n",ob->query("name"),ob->query("id"));
        input_to("check1",0, me,ob);
        return ;
        }

        if( str[0]!='y' && str[0]!='Y' ) {
                write("你放棄了更改密碼。\n");
                return ;
        }
        else {
                write("依據規定,該玩家的密碼將被設為12345 !!!\n");
                pass="12345";
                ob->set("password",crypt(pass,0));
                ob->save();
                log_file( "CHANGEPW", sprintf("%s(%s) 更換 %s(%s) 的密碼在 (%s)\n",
                  me->query("name"),me->query("id"),
                  ob->query("name"), ob->query("id"),
                   ctime(time()) ) );
                write("密碼更改完畢!!!\n");
                destruct(ob);
                return ;
        }
}


int help()
{
        write(@TEXT
指令格式﹕chpw 玩家id

這是因為總是有些玩家會把密碼忘了,所以才設的指令
指令中內定該玩家的密碼將被設為12345....

TEXT
        );
        return 1;
}
