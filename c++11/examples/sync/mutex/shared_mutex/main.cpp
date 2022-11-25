class DNSCache
{
private:
    std::unordered_map<std::string, std::string> m_UrlDict;
    std::shared_mutex m_mutex; 

public:
	void writer(const std::string& name, const std::string& ip)
	{
    		std::unique_lock lock(m_mutex);
    		m_UrlDict[name] = ip;
	}

	std::string reader(const std::string& name)
	{
    		try
    		{
        		std::shared_lock lock(m_mutex);
        		return m_UrlDict.at(name);
    		}
    		catch(...)
    		{
        		return "Unknown host name";
    		}
	}

};

int main(int argc, char** argv) {

}
