// message.c

varargs void message_vision(string msg, object me, object you , string type)
{
	string my_gender, your_gender, my_name, your_name;
	string str1, str2, str3,channel_type;
	my_name= (string)me->name();
	my_gender = (string)me->query("gender");
  
  if(stringp(type) )
    channel_type = "vision:"+type;
  else if(sscanf(file_name(previous_object()),"/daemon/skill/%*s"))
    channel_type = "vision:combat";

  else
    channel_type = "vision";
  if(!environment(me) || (you && !environment(you))) return ;

	str1 = replace_string(msg,  "$P", gender_self(my_gender));
	str1 = replace_string(str1, "$N", gender_self(my_gender));
	str3 = replace_string(msg,  "$P", my_name);
	str3 = replace_string(str3, "$N", my_name);
	if( you ) {
		your_name= (string)you->name();
		your_gender= (string)you->query("gender");
		str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
		str2 = replace_string(str2, "$p", gender_self(your_gender));
		str2 = replace_string(str2, "$N", my_name);
		str2 = replace_string(str2, "$n", gender_self(your_gender));
		message(channel_type, str2, you,);
		str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
		str1 = replace_string(str1, "$n", your_name);
		str3 = replace_string(str3, "$p", your_name);
		str3 = replace_string(str3, "$n", your_name);
	}
	message(channel_type, str1, me);
    if(you)
	message(channel_type, str3,  environment(me), ({me, you}) );
    else
       if(environment(me) && living(environment(me) ))
    message(channel_type, str3, all_inventory(environment(me))+ ({ environment(me) }) , ({me}) );
else if(environment(me))
     message(channel_type, str3, environment(me) , ({me}) );
}

void tell_object(object ob, string str)
{
	message("tell_object", str, ob);
}

varargs void tell_room(mixed ob, string str, object *exclude)
{
	if( ob ) message("tell_room", str, ob, exclude);
}

void shout(string str)
{
	message("shout", str, 
		filter_array(users(), "listen_me", this_object()),
		this_player());
}

void write(string str)
{
        if(!str) return ;
	if( this_player() )
		message("write", str, this_player());
	else if( previous_object() )
		message("write", str, previous_object());
	else
		efun::write(str);
}

varargs void say(string str, mixed exclude)
{
	if( living(previous_object()) )
		message("say", str, environment(previous_object()), ({ previous_object(),exclude }) );
	else if( this_player() )
		message("say", str, environment(this_player()), ({ this_player() , exclude }));
}

int listen_me(object who)
{
  if (who->gage(this_player())) return 0;
  else return 1;
}

