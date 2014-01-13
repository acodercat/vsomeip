//
// payload_impl.hpp
//
// Date: 	Jan 9, 2014
// Author: 	Lutz Bichler
//
// This file is part of the BMW Some/IP implementation.
//
// Copyright © 2013 Bayerische Motoren Werke AG (BMW). 
// All rights reserved.
//

#ifndef PAYLOAD_IMPL_HPP
#define PAYLOAD_IMPL_HPP

#include <vsomeip/payload.hpp>
#include <vector>

namespace vsomeip {

class serializer;
class deserializer;

class payload_impl : public payload {
public:
	payload_impl();
	payload_impl(const payload_impl& payload);
	virtual ~payload_impl();

	virtual uint8_t * get_data();
	virtual uint32_t get_length() const;
	virtual void set_data(const uint8_t *data, uint32_t length);
	virtual void set_data(const std::vector<uint8_t>& data);

	virtual bool serialize(serializer *_to) const;
	virtual bool deserialize(deserializer *_from);

private:
	std::vector<uint8_t> data_;
};

} // namespace vsomeip

#endif // PAYLOAD_IMPL_HPP