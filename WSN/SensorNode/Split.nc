interface Split {
	command void SplitAndSend(uint8_t* buffer, uint16_t size, uint32_t timest);
	event void SendDone();
	command void Start();
	async event void StartDone();
}
