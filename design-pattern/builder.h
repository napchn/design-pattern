#pragma once

#include <string>
#include <list>

typedef struct FileHeader {
	std::string company_id;
	std::string created_time;
} FileHeader;

typedef struct FileBody {
	std::string trans_id;
	double quantity;
} FileBody;

typedef struct FileFooter {
	std::string created_user;
} FileFooter;

class Builder {
public:
	virtual void CreateFileHeader(const FileHeader &header) = 0;
	virtual void CreateFileBody(const std::list<FileBody> &body) = 0;
	virtual void CreateFileFooter(const FileFooter &footer) = 0;
	virtual std::string GetFile() = 0;
};

class TxtBuilder : public Builder {
public:
	void CreateFileHeader(const FileHeader& header) {
		txt.append(header.company_id + " " + header.created_time + "\n");
	};

	void CreateFileBody(const std::list<FileBody>& body) {
		for (std::list<FileBody>::const_iterator it = body.begin(); it != body.end(); ++it) {
			txt.append((*it).trans_id + "\t" + std::to_string((*it).quantity) + "\n");
		}
	};

	void CreateFileFooter(const FileFooter& footer) {
		txt.append(footer.created_user + "\n");
	};

	std::string GetFile() {
		return txt;
	};

private:
	std::string txt;
};

class XmlBuilder : public Builder {
public:
	XmlBuilder() {
		space = "    ";
	};

	void CreateFileHeader(const FileHeader& header) {
		xml.append("<?xml version=\"1.0\" encoding=\"utf - 8\"?>\n");
		xml.append("<root>\n");
		xml.append(space + "<header>\n");
		xml.append(space + space + "<company-id>" + header.company_id + "<\\company-id>\n");
		xml.append(space + space + "<created-time>" + header.created_time + "<\\created-time>\n");
		xml.append(space + "<\\header>\n");
	};

	void CreateFileBody(const std::list<FileBody>& body) {
		xml.append(space + "<body>\n");
		for (std::list<FileBody>::const_iterator it = body.begin(); it != body.end(); ++it) {
			xml.append(space + space + "<item>\n");
			xml.append(space + space + space + "<trans-id>" + (*it).trans_id + "<\\trans-id>\n");
			xml.append(space + space + space + "<quantity>" + std::to_string((*it).quantity) + "<\\quantity>\n");
			xml.append(space + space + "<\\item>\n");
		}
		xml.append(space + "<\\body>\n");
	};

	void CreateFileFooter(const FileFooter& footer) {
		xml.append(space + "<footer>\n");
		xml.append(space + space + "<user>" + footer.created_user + "<\\user>\n");
		xml.append(space + "<\\footer>\n");
		xml.append("<\\root>\n");
	};

	std::string GetFile() {
		return xml;
	};

private:
	std::string xml;
	std::string space;
};

class Director {
public:
	Director(Builder* builder) : builder(builder) {};

	void Construct(const FileHeader &header, const std::list<FileBody>& body, const FileFooter& footer) {
		builder->CreateFileHeader(header);
		builder->CreateFileBody(body);
		builder->CreateFileFooter(footer);
	};

private:
	Builder* builder;
};

