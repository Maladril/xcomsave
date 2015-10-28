#ifndef XCOMREADER_H
#define XCOMREADER_H

#include <stdint.h>
#include <string>

#include "xcom.h"

class XComReader
{
public:
	XComReader(const unsigned char *ptr, long len) :
		ptr_(ptr), start_(ptr), length_(len) {}

	XComSave getSaveData();

private:
	uint32_t readInt32();
	float readFloat();
	const char* readString();
	bool readBool();
	XComSaveHeader readHeader();
	XComActorTable readActorTable();
	XComCheckpointTable readCheckpointTable();
	std::vector<std::unique_ptr<XComProperty>> readProperties(uint32_t dataLen);
	XComActorTemplateTable readActorTemplateTable();
	XComNameTable readNameTable();
	int32_t getUncompressedSize();
	void getUncompressedData(unsigned char *);

private:
	const unsigned char *ptr_;
	const unsigned char *start_;
	long length_;
};
#endif //XCOM_H