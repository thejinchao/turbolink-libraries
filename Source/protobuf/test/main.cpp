#include <stdio.h>

#include <google/protobuf/descriptor_database.h>
#include "google/protobuf/util/json_util.h"
#include "person.pb.h"

using namespace test;

google::protobuf::Message* createMessage(const std::string& typeName)
{
	google::protobuf::Message* message = nullptr;

	const google::protobuf::Descriptor* descriptor = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(typeName);
	if (descriptor)
	{
		const google::protobuf::Message* prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
		if (prototype)
		{
			message = prototype->New();
		}
	}
	return message;
}

int main(int argc, char* argv[])
{
	std::string stream;
	{
		Person person;

		person.set_name("jinchao");
		person.set_id(123);
		person.set_email("thejinchao@gmail.com");

		Person::PhoneNumber* phone1 = person.add_phones();
		phone1->set_number("1234");
		phone1->set_type(Person::MOBILE);

		Person::PhoneNumber* phone2 = person.add_phones();
		phone2->set_number("5678");
		phone2->set_type(Person::WORK);

		person.SerializeToString(&stream);
	}

	//---------------------------
	{
		Person person;
		person.ParseFromString(stream);

		std::cout << "Name: " << person.name() << std::endl;
		std::cout << "ID: " << person.id() << std::endl;
		for (int i = 0; i < person.phones_size(); i++) {
			const Person::PhoneNumber phone = person.phones(i);

			switch (phone.type()) {
			case Person::MOBILE:
				std::cout << "Mobile: "; break;
			case Person::HOME:
				std::cout << "Home: "; break;
			case Person::WORK:
				std::cout << "Work: "; break;
			default:
				std::cout << "Unknown: "; break;
			}
			std::cout << phone.number() << std::endl;
		}
	}

	std::cout << "----------------" << std::endl;

	//---------------------------
	{
		Person* person = static_cast<Person*>(createMessage("test.Person"));
		person->ParseFromString(stream);

		std::cout << "Name: " << person->name() << std::endl;
		std::cout << "ID: " << person->id() << std::endl;
		for (int i = 0; i < person->phones_size(); i++) {
			const Person::PhoneNumber phone = person->phones(i);

			switch (phone.type()) {
			case Person::MOBILE:
				std::cout << "Mobile: "; break;
			case Person::HOME:
				std::cout << "Home: "; break;
			case Person::WORK:
				std::cout << "Work: "; break;
			default:
				std::cout << "Unknown: "; break;
			}
			std::cout << phone.number() << std::endl;
		}
	}
	return 0;
}
