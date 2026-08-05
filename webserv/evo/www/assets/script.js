// Genel fetch isteği atan yardımcı fonksiyon (DELETE ve UNKNOWN testleri için)
async function sendFetchRequest(method, inputId, resultId) {
	const target = document.getElementById(inputId).value;
	const resultDiv = document.getElementById(resultId);
	
	if(!target) {
		alert("Lütfen geçerli bir hedef yol (URL) girin.");
		return;
	}

	// Arayüz sıfırlama
	resultDiv.className = 'mt-3 p-3 rounded-lg text-sm font-mono border font-bold';
	resultDiv.style.display = 'block';
	resultDiv.textContent = 'İstek gönderiliyor... (Sunucu yanıtı bekleniyor)';

	try {
		const response = await fetch(target, { method: method });
		
		const statusText = response.statusText || 'Bilinmeyen Durum';
		const message = `HTTP ${response.status} ${statusText}\n\n`;
		
		if (response.ok) {
			resultDiv.classList.add('bg-green-100', 'text-green-800', 'border-green-300');
			resultDiv.innerText = message + "İstek Başarılı!";
		} else {
			// Sunucunun döndürdüğü hata durumları
			resultDiv.classList.add('bg-orange-100', 'text-orange-900', 'border-orange-300');
			resultDiv.innerText = message + "Sunucu bir hata kodu döndürdü (Bu testin amacına göre doğru çalışıyor olabilirsiniz).";
		}
	} catch (error) {
		// Fetch ağ düzeyinde başarısız olursa (Sunucu çökmesi veya CORS engeli)
		resultDiv.classList.add('bg-red-100', 'text-red-900', 'border-red-300');
		resultDiv.innerText = `AĞ HATASI (Sunucu çökmüş, port kapanmış veya geçersiz metot bağlantıyı koparmış olabilir):\n\n${error.message}`;
	}
}

// Büyük Payload (Body Limit) testi için fonksiyon
async function testHugePayload() {
	const target = document.getElementById('hugePayloadUrl') ? document.getElementById('hugePayloadUrl').value : document.getElementById('bodyLimitUrl').value;
	const resultDiv = document.getElementById('hugePayloadResult');
	const btn = document.getElementById('hugePayloadBtn');
	
	// UI Güncelleme
	btn.disabled = true;
	btn.innerText = "Veri Üretiliyor ve Gönderiliyor...";
	resultDiv.className = 'mt-3 p-3 rounded-lg text-sm font-mono border font-bold block';
	
	try {
		// Yaklaşık 10 MB'lık (10 milyon karakter) devasa bir string oluşturalım
		const chunk = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"; // 62 byte
		let hugeData = "";
		for(let i=0; i < 160000; i++) {
			hugeData += chunk;
		}

		const response = await fetch(target, {
			method: 'POST',
			headers: { 'Content-Type': 'text/plain' },
			body: hugeData
		});

		if (response.status === 413) {
			resultDiv.classList.add('bg-green-100', 'text-green-800', 'border-green-300');
			resultDiv.innerText = `BAŞARILI: Sunucu tam istendiği gibi "HTTP 413 Payload Too Large" hatası döndürdü.`;
		} else {
			resultDiv.classList.add('bg-red-100', 'text-red-900', 'border-red-300');
			resultDiv.innerText = `BEKLENMEYEN YANIT: HTTP ${response.status} ${response.statusText}\n(Sunucu 413 döndürmedi. Body limit (client_max_body_size) ayarlarını kontrol edin veya sunucu çökmeden veriyi tamamen kabul etti.)`;
		}
	} catch (error) {
		resultDiv.classList.add('bg-red-100', 'text-red-900', 'border-red-300');
		resultDiv.innerText = `AĞ HATASI VEYA ÇÖKME:\n\n${error.message}\n\n(Sunucu büyük veriyi alırken belleği tüketip çökmüş olabilir. Terminalden hata logunu kontrol edin.)`;
	} finally {
		btn.disabled = false;
		btn.innerText = "10 MB Payload Gönder";
	}
}